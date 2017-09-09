#include <TMB.hpp>

typedef Eigen::Matrix<double,Eigen::Dynamic,1> vector_double;

void tmb_forward(SEXP f, const vector_double &x, vector_double &y) {
  SEXP tag=R_ExternalPtrTag(f);
  if(!strcmp(CHAR(tag), "ADFun")) {
    ADFun<double>* pf;
    pf = (ADFun<double>*) R_ExternalPtrAddr(f);
    y = pf->Forward(0, x);
  } else
  if(!strcmp(CHAR(tag), "parallelADFun")) {
    parallelADFun<double>* pf;
    pf = (parallelADFun<double>*) R_ExternalPtrAddr(f);
    y = pf->Forward(0, x);
  } else
    Rf_error("Unknown function pointer");
}

void tmb_reverse(SEXP f, const vector_double &x, vector_double &y) {
  SEXP tag=R_ExternalPtrTag(f);
  if(!strcmp(CHAR(tag), "ADFun")) {
    ADFun<double>* pf;
    pf = (ADFun<double>*) R_ExternalPtrAddr(f);
    vector_double v(1);
    v(0) = 1.;
    y = pf->Reverse(1, v);
  } else
  if(!strcmp(CHAR(tag), "parallelADFun")) {
    parallelADFun<double>* pf;
    pf = (parallelADFun<double>*) R_ExternalPtrAddr(f);
    vector_double v(1);
    v(0) = 1.;
    y = pf->Reverse(1, v);
  } else
    Rf_error("Unknown function pointer");
}

template<class Type>
Type objective_function<Type>::operator() ()
{
  return 0;
}