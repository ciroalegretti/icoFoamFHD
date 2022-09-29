{
	forAll(M0,i)
	{
	    double alpha_mC = alpha_m[i];
	    
	    double lang = (1.0/(Foam::tanh(alpha_mC)) - 1.0/(alpha_mC));
	    double    E = (8*3.1415/alpha_mC) * lang * (1.0 - pow(1.0/(Foam::sinh(alpha_mC)),2));
	    
	    double    F = Foam::sqr(8*3.1415/alpha_mC)*pow(lang,2)*(pow(alpha_mC,2)*pow(1.0/(Foam::sinh(alpha_mC)),2)*(1.0/Foam::tanh(alpha_mC)) - 1.0/alpha_mC );
	    
	    double    G = (3.1415/(2*alpha_mC))*E;
	    
	    M0[i][0] = 0.0;
	    M0[i][1] = Md.value() *( lang * vf.value() + E * lambda.value() * pow(vf.value(),2) + (F + G)*pow(lambda.value(),2)*pow(vf.value(),3));
	    M0[i][2] = 0.0;

	}  
}
