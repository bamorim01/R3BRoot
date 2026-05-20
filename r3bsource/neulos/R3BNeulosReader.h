#ifndef R3BNEULOSREADER_H
#define R3BNEULOSREADER_H 1

#include "R3BReader.h"

#include <stdint.h>

class TClonesArray;

struct EXT_STR_h101_NEULOS_t;
typedef struct EXT_STR_h101_NEULOS_t EXT_STR_h101_NEULOS;
typedef struct EXT_STR_h101_NEULOS_onion_t EXT_STR_h101_NEULOS_onion;

class ext_data_struct_info;

class R3BNeulosReader : public R3BReader
{
  public:
    R3BNeulosReader(EXT_STR_h101_NEULOS_onion*, size_t);

    virtual ~R3BNeulosReader();

    virtual Bool_t Init(ext_data_struct_info*) override;

    virtual Bool_t R3BRead() override;

    virtual void Reset() override;

    void SetOnline(Bool_t option) { fOnline = option; }

  private:
    unsigned int fNEvent;

    EXT_STR_h101_NEULOS_onion* fData;

    size_t fOffset;

    Bool_t fOnline;

    TClonesArray* fArray;

  public:
    ClassDefOverride(R3BNeulosReader, 1);
};

#endif
