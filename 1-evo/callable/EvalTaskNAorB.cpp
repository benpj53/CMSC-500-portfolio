#ifndef MABE_EVAL_TASK_NAORB_H
#define MABE_EVAL_TASK_NAORB_H

#include "./EvalTaskBase.hpp"

namespace mabe {

  /// \brief Tests organism output for bitwise NAORB operation
  class EvalTaskNAorB : public EvalTaskBase<EvalTaskNAorB, 2> {

  public:
    EvalTaskNAorB(mabe::MABE & control,
                  const std::string & name="EvalTaskNAorB",
                  const std::string & desc="Evaluate organism on NAORB logic task")
      : EvalTaskBase(control, name, "NAORB", desc){;}

    ~EvalTaskNAorB() { }
    
    /// Check if the passed output is equal to not input_a or input_b  
    bool CheckTwoArg(const data_t& output, const data_t& input_a, const data_t& input_b){
      return output == (~input_a | input_b);
    }
  };

  MABE_REGISTER_MODULE(EvalTaskNAorB, "Organism-triggered evaluation of NAORB operation");

}

#endif
