#ifndef FUNCAOOPERADORES_H
#define FUNCAOOPERADORES_H
#include "funcoesReais.h"
namespace tnw {
	namespace op {
		tnw::FuncaoRealP compose(const tnw::FuncaoRealP& f, const tnw::FuncaoRealP& g);

		tnw::FuncaoRealP operator+(const tnw::FuncaoRealP& f, const tnw::FuncaoRealP& g);
		tnw::FuncaoRealP operator-(const tnw::FuncaoRealP& f, const tnw::FuncaoRealP& g);
		tnw::FuncaoRealP operator*(const tnw::FuncaoRealP& f, const tnw::FuncaoRealP& g);
		tnw::FuncaoRealP operator/(const tnw::FuncaoRealP& f, const tnw::FuncaoRealP& g);
		tnw::FuncaoRealP pow(const tnw::FuncaoRealP& f, const tnw::FuncaoRealP& g);

		tnw::FuncaoRealP operator+(const tnw::FuncaoRealP& f, double v);
		tnw::FuncaoRealP operator-(const tnw::FuncaoRealP& f, double v);
		tnw::FuncaoRealP operator*(const tnw::FuncaoRealP& f, double v);
		tnw::FuncaoRealP operator/(const tnw::FuncaoRealP& f, double v);
		tnw::FuncaoRealP pow(const tnw::FuncaoRealP& f, double v);

		tnw::FuncaoRealP operator+(double v, const tnw::FuncaoRealP& g);
		tnw::FuncaoRealP operator-(double v, const tnw::FuncaoRealP& g);
		tnw::FuncaoRealP operator*(double v, const tnw::FuncaoRealP& g);
		tnw::FuncaoRealP operator/(double v, const tnw::FuncaoRealP& g);
		tnw::FuncaoRealP pow(double v, const tnw::FuncaoRealP& g);
	}
}
#endif