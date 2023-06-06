#ifndef MABE_EVAL_TASK_NAANDB_H
#define MABE_EVAL_TASK_NAANDB_H

#include "./EvalTaskBase.hpp"

namespace mabe {

  /// \brief Tests organism output for bitwise NOTAANDB operation
  class EvalTaskNAandB : public EvalTaskBase<MABE_EVAL_TASK_NAANDB_H, 2> {

  public:
    EvalTaskNAandB(mabe::MABE & control,
                  const std::string & name="EvalTaskNAandB",
                  const std::string & desc="Evaluate organism on NOTAANDB logic task")
      : EvalTaskBase(control, name, "NOTAANDB", desc){;}

    ~EvalTaskNAandB() { }
    
    /// Check if the passed output is equal to not input_a and equal to input_b  
    bool CheckTwoArg(const data_t& output, const data_t& input_a, const data_t& input_b){
      return output == (~input_a & input_b);
    }
  };

  MABE_REGISTER_MODULE(EvalTaskNAandB, "Organism-triggered evaluation of NOTAANDB operation");

}

#endif
