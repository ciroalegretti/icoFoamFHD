{
	forAll(alpha_m,i)
	{
	       
	    alpha_m[i] = mu0.value() * m.value() * modH[i]/ (Kb.value() * T[i]);
	    
	}    
}
