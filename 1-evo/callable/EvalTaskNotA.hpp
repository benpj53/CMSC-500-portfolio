#ifndef MABE_EVAL_TASK_NotA_H
#define MABE_EVAL_TASK_NotA_H

#include "./EvalTaskBase.hpp"

namespace mabe {

  /// \brief Tests organism output for bitwise not A operation
  class EvalTaskNotA : public EvalTaskBase<EvalTaskNotA, 2> {

  public:
    EvalTaskNotA(mabe::MABE & control,
                  const std::string & name="EvalTaskNotA",
                  const std::string & desc="Evaluate organism on not A logic task")
      : EvalTaskBase(control, name, "notA", desc){;}

    ~EvalTaskNotA() { }
    
    /// Check if the passed output is not equal to input_a
    bool CheckTwoArg(const data_t& output, const data_t& input_a, const data_t& input_b){
      return output == ~input_a;
    }
  };

  MABE_REGISTER_MODULE(EvalTaskNotA, "Organism-triggered evaluation of not A operation");

}

#endif
