#ifndef LM_LM_EXCEPTION__
#define LM_LM_EXCEPTION__

// Named to avoid conflict with util/exception.hh.  

#include "libKenLM/util/exception.hh"
#include "libKenLM/util/string_piece.hh"

#include <exception>
#include <string>

namespace lm {

typedef enum {THROW_UP, COMPLAIN, SILENT} WarningAction;

class ConfigException : public util::Exception {
  public:
    ConfigException() throw();
    ~ConfigException() throw();
};

class LoadException : public util::Exception {
   public:
      virtual ~LoadException() throw();

   protected:
      LoadException() throw();
};

class FormatLoadException : public LoadException {
  public:
    FormatLoadException() throw();
    ~FormatLoadException() throw();
};

class VocabLoadException : public LoadException {
  public:
    virtual ~VocabLoadException() throw();
    VocabLoadException() throw();
};

class SpecialWordMissingException : public VocabLoadException {
  public:
    explicit SpecialWordMissingException() throw();
    ~SpecialWordMissingException() throw();
};

} // namespace lm

#endif // LM_LM_EXCEPTION
