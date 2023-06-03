#include <iostream>
#include <functional>

using namespace std;

template<typename T>
class HanoiTower {
public:
    HanoiTower(T numDiscos, T torreInicio, T torreFinal) : numDiscos(numDiscos), torreInicio(torreInicio), torreFinal(torreFinal), totalMoves(0) {}

    void setNumDiscos(T num);

    T getNumDiscos() const;

    void resolver();

    T getMovTotales() const;

    ~HanoiTower();

private:
    T numDiscos;
    T torreInicio;
    T torreFinal;
    T totalMoves;
};