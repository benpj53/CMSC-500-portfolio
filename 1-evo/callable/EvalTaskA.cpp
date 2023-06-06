#ifndef MABE_EVAL_TASK_A_H
#define MABE_EVAL_TASK_A_H

#include "./EvalTaskBase.hpp"

namespace mabe {

  /// \brief Tests organism output for bitwise A operation
  class EvalTaskA : public EvalTaskBase<EvalTaskA, 2> {

  public:
    EvalTaskA(mabe::MABE & control,
                  const std::string & name="EvalTaskA",
                  const std::string & desc="Evaluate organism on A logic task")
      : EvalTaskBase(control, name, "a", desc){;}

    ~EvalTaskA() { }
    
    /// Check if the passed output is equal to input_a 
    bool CheckTwoArg(const data_t& output, const data_t& input_a, const data_t& input_b){
      return output == input_a;
    }
  };

  MABE_REGISTER_MODULE(EvalTaskA, "Organism-triggered evaluation of A operation");

}

#endif
