#ifndef MABE_EVAL_TASK_NotB_H
#define MABE_EVAL_TASK_NotB_H

#include "./EvalTaskBase.hpp"

namespace mabe {

  /// \brief Tests organism output for bitwise not B operation
  class EvalTaskNotB : public EvalTaskBase<EvalTaskNotB, 2> {

  public:
    EvalTaskNotB(mabe::MABE & control,
                  const std::string & name="EvalTaskNotB",
                  const std::string & desc="Evaluate organism on not B logic task")
      : EvalTaskBase(control, name, "notB", desc){;}

    ~EvalTaskNotB() { }
    
    /// Check if the passed output is not equal to input_b  
    bool CheckTwoArg(const data_t& output, const data_t& input_a, const data_t& input_b){
      return output == ~input_b;
    }
  };

  MABE_REGISTER_MODULE(EvalTaskNotB, "Organism-triggered evaluation of not B operation");

}

#endif
