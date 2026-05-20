#ifndef R3BSFRSFIBONEREADER_H
#define R3BSFRSFIBONEREADER_H 1

#include "R3BReader.h"

#include <stdint.h>

class TClonesArray;

struct EXT_STR_h101_SFRS_FIB_ONE_t;
typedef struct EXT_STR_h101_SFRS_FIB_ONE_t EXT_STR_h101_SFRS_FIB_ONE;
typedef struct EXT_STR_h101_SFRS_FIB_ONE_onion_t EXT_STR_h101_SFRS_FIB_ONE_onion;

class ext_data_struct_info;

class R3BSfrsFibOneReader : public R3BReader
{
  public:
    R3BSfrsFibOneReader(EXT_STR_h101_SFRS_FIB_ONE_onion*, size_t);

    virtual ~R3BSfrsFibOneReader();

    virtual Bool_t Init(ext_data_struct_info*) override;

    virtual Bool_t R3BRead() override;

    virtual void Reset() override;

    void SetOnline(Bool_t option) { fOnline = option; }

  private:
    unsigned int fNEvent;

    EXT_STR_h101_SFRS_FIB_ONE_onion* fData;

    size_t fOffset;

    Bool_t fOnline;

    TClonesArray* fArray;

  public:
    ClassDefOverride(R3BSfrsFibOneReader, 1);
};

#endif
