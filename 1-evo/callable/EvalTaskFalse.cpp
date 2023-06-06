#ifndef MABE_EVAL_TASK_FALSE_H
#define MABE_EVAL_TASK_FALSE_H

#include "./EvalTaskBase.hpp"

namespace mabe {

  /// \brief Tests organism output for bitwise false operation
  class EvalTaskFalse : public EvalTaskBase<EvalTaskFalse, 2> {

  public:
    EvalTaskFalse(mabe::MABE & control,
                  const std::string & name="EvalTaskFalse",
                  const std::string & desc="Evaluate organism on false logic task")
      : EvalTaskBase(control, name, "false", desc){;}

    ~EvalTaskFalse() { }
    
    /// Return false upon evaluation  
    bool CheckTwoArg(const data_t& output, const data_t& input_a, const data_t& input_b){
      return false;
    }
  };

  MABE_REGISTER_MODULE(EvalTaskFalse, "Organism-triggered evaluation of false operation");

}

#endif
