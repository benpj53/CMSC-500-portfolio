#ifndef MABE_EVAL_TASK_AANDNB_H
#define MABE_EVAL_TASK_AANDNB_H

#include "./EvalTaskBase.hpp"

namespace mabe {

  /// \brief Tests organism output for bitwise AANDNOTB operation
  class EvalTaskAandNB : public EvalTaskBase<EvalTaskAandNB, 2> {

  public:
    EvalTaskAandNB(mabe::MABE & control,
                  const std::string & name="EvalTaskAandNB",
                  const std::string & desc="Evaluate organism on AANDNOTB logic task")
      : EvalTaskBase(control, name, "AANDNOTB", desc){;}

    ~EvalTaskAandNB() { }
    
    /// Check if the passed output is equal to input_a and not input_b  
    bool CheckTwoArg(const data_t& output, const data_t& input_a, const data_t& input_b){
      return output == (input_a & ~input_b);
    }
  };

  MABE_REGISTER_MODULE(EvalTaskAandNB, "Organism-triggered evaluation of AANDNOTB operation");

}

#endif
