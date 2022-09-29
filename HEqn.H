{
	forAll(H,i)
	{
	    //const scalar x = mesh.C() [i][0];
	    const scalar y = mesh.C() [i][1];
	    //const scalar z = mesh.C() [i][2];
	    
	    H[i][0] = 0.0;
	    H[i][1] = (1.0e+5)*(1 - y);
	    H[i][2] = 0.0;
	}    
	forAll(modH,i)
	{
	    modH[i] = mag(H[i]);
	}    
}
