bool __stdcall init_COVER_TransMercator(const CoordSys cs, int zone, double lam); 
void __stdcall Close_COVER_TransMercator();
bool  __stdcall bl2xy_COVER_TransMercator(const double& phi, const double& lam, double& x, double& y);
bool  __stdcall xy2bl_COVER_TransMercator(const double& x, const double& y, double& phi, double& lam);
