#ifndef MABE_EVAL_TASK_TRUE_H
#define MABE_EVAL_TASK_TRUE_H

#include "./EvalTaskBase.hpp"

namespace mabe {

  /// \brief Tests organism output for bitwise true operation
  class EvalTaskTrue : public EvalTaskBase<EvalTaskTrue, 2> {

  public:
    EvalTaskTrue(mabe::MABE & control,
                  const std::string & name="EvalTaskTrue",
                  const std::string & desc="Evaluate organism on true logic task")
      : EvalTaskBase(control, name, "true", desc){;}

    ~EvalTaskTrue() { }
    
    // Return true upon evaluation  
    bool CheckTwoArg(const data_t& output, const data_t& input_a, const data_t& input_b){
      return true;
    }
  };

  MABE_REGISTER_MODULE(EvalTaskTrue, "Organism-triggered evaluation of true operation");

}

#endif
