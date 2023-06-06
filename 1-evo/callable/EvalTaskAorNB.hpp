#ifndef MABE_EVAL_TASK_AorNB_H
#define MABE_EVAL_TASK_AorNB_H

#include "./EvalTaskBase.hpp"

namespace mabe {

  /// \brief Tests organism output for bitwise AORNOTB operation
  class EvalTaskAorNB : public EvalTaskBase<EvalTaskAorNB, 2> {

  public:
    EvalTaskAorNB(mabe::MABE & control,
                  const std::string & name="EvalTaskAorNB",
                  const std::string & desc="Evaluate organism on AORNOTB logic task")
      : EvalTaskBase(control, name, "AORNOTB", desc){;}

    ~EvalTaskAorNB() { }
    
    /// Check if the passed output is equal to input_a or not input_b  
    bool CheckTwoArg(const data_t& output, const data_t& input_a, const data_t& input_b){
      return output == (input_a | ~input_b);
    }
  };

  MABE_REGISTER_MODULE(EvalTaskAorNB, "Organism-triggered evaluation of AORNOTB operation");

}

#endif
