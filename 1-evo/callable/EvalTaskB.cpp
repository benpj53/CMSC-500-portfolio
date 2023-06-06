#ifndef MABE_EVAL_TASK_B_H
#define MABE_EVAL_TASK_B_H

#include "./EvalTaskBase.hpp"

namespace mabe {

  /// \brief Tests organism output for bitwise B operation
  class EvalTaskB : public EvalTaskBase<EvalTaskB, 2> {

  public:
    EvalTaskB(mabe::MABE & control,
                  const std::string & name="EvalTaskB",
                  const std::string & desc="Evaluate organism on B logic task")
      : EvalTaskBase(control, name, "B", desc){;}

    ~EvalTaskB() { }
    
    /// Check if the passed output is equal to input_b  
    bool CheckTwoArg(const data_t& output, const data_t& input_a, const data_t& input_b){
      return output == input_b;
    }
  };

  MABE_REGISTER_MODULE(EvalTaskB, "Organism-triggered evaluation of B operation");

}

#endif
