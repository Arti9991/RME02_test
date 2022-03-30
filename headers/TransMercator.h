
#ifndef TransMercatorH
#define TransMercatorH

enum CoordSys {
  SK42,  // Система координат 42 года (эллипсоид Красовского / проекция Гаусса-Крюгера)
  UTM    // WGS84 / UTM
};

// Геодезические координаты - в радианах (phi - широта, lam - долгота);
// прямоугольные координаты - в метрах (x - на север, у - на восток).
class TransMercator {
public:
  TransMercator();
  int __stdcall init(int cs, int zone, double lam = 0.);
  bool __stdcall bl2xy(const double& phi, const double& lam, double& x, double& y);
  bool __stdcall xy2bl(const double& x, const double& y, double& phi, double& lam);
  double getCentralMeridian() const
    { return lam0; }
  int getZone() const
    { return mZone; }
private:
  static const int EN_SIZE = 5;
  bool mInitialized;
  int mZone;
  double
    a,          // major axis or radius if es==0
    es,         // e ^ 2
    e,          // eccentricity
    esp,
    en[EN_SIZE],
    ml0,
    ra,         // 1/A
    one_es,     // 1 - e^2
    lam0, phi0, // central longitude, latitude
    k0,         // general scaling factor
    x0, y0,     // false easting, northing
    to_meter, fr_meter; // cartesian scaling
};

#endif //TransMercatorH
