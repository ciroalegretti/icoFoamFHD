{
	#include "M0Eqn.H"

        fvVectorMatrix MEqn
        (
            fvm::ddt(M)
            + fvm::div(phi,M)
        );
	
	volVectorField MxH = M^H;
	
	solve(MEqn == (0.5*(fvc::curl(U) ^ M)
		    + (mu0 / (6*nu*rho * vf))*(MxH ^ M)
		    + (1 / tb)*(M0 - M)));
}
