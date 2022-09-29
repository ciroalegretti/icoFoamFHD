{
	forAll(M0,i)
	{
	    double alpha_mC = alpha_m[i];
	    
	    M0[i][0] = 0.0;
	    M0[i][1] = vf.value() * Md.value() * (1.0/(Foam::tanh(alpha_mC)) - 1.0/(alpha_mC));
	    M0[i][2] = 0.0;

	}  
}
