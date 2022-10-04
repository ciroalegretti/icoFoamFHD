{
	/*double re = 0.0;
	double pr = 0.0;
	double ec = 0.0;
	double pe = 0.0;
	double nu = 0.0;
	double psiMin = 0.0;
	
		
	re = rho * U.component(0).(patch=topLid)
	
	
	*/
	double L = 0.1; 
	/*double Nu = 0.0;
	
	label patchIDbot = mesh.boundaryMesh().findPatchID("bottomWall");
	scalarField freeSurfaceTgrad(T.boundaryField()[patchIDbot].snGrad());
	
	Nu = L * fvc::grad(T).boundaryField()[bottomWall];
	*/
	
	#include <fstream>
	#include <iostream>
	
	Info<< "Writting computed parameters \n" << endl;
	
	std::ofstream write_pp("output.dat");
	
	//write_pp.setf(std::ios::scientific);
	write_pp.precision(4);
	
	write_pp << "Dimensionless equivalents: \n" << endl;
	write_pp << "Re \t" << (rho*mag(max(U.component(0)))*L/nu).value() << nl << endl;
	write_pp << "Pr \t" << (nu/alpha).value() << nl << endl;
	write_pp << "Pe \t" << (tb/(L*mag(max(U.component(0))))).value() << nl << endl;
	//write_pp << "Nu \t" << Nu.value() << endl;
	//write_pp << "Psi_min \t" << -(min(U).value() << nl << endl;
	
	write_pp.close();
}
