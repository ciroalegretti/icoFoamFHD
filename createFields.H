Info<< "Reading transportProperties\n" << endl;

IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

// uniform and constant imported from dict

dimensionedScalar nu
(
    "nu",
    dimViscosity,
    transportProperties.lookup("nu")
);

dimensionedScalar mu0
(
    "mu0",
    transportProperties.lookup("mu0")
);

dimensionedScalar vf // volumetric fraction of suspended particles
(
    "vf",
    transportProperties.lookup("vf")
);

dimensionedScalar Pe
(
    "Pe",
    transportProperties.lookup("Pe")
);

dimensionedScalar alpha
(
     "alpha",
     transportProperties.lookup("alpha")
);

dimensionedScalar Md
(
     "Md",
     transportProperties.lookup("Md")
);

dimensionedScalar Kb
(
     "Kb",
     transportProperties.lookup("Kb")
);

dimensionedScalar m
(
     "m",
     transportProperties.lookup("m")
);

// scalar fields

Info<< "Reading field p\n" << endl;
volScalarField p
(
    IOobject
    (
        "p",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field T\n" << endl;
volScalarField T
(
    IOobject
    (
        "T",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

/*
Info<< "Reading field phi_m\n" << endl;
volScalarField phi_m
(
    IOobject
    (
        "phi_m",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);
*/



Info<< "Reading field U\n" << endl;
volVectorField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field M\n" << endl;
volVectorField M
(
    IOobject
    (
        "M",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


Info<< "Reading field H\n" << endl;
volVectorField H
(
    IOobject
    (
        "H",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);
//
forAll(H,i)
{
    //const scalar x = mesh.C() [i][0];
    const scalar y = mesh.C() [i][1];
    //const scalar z = mesh.C() [i][2];
    
    H[i][0] = 0.0;
    H[i][1] = (1.0e+5)*y;
    H[i][2] = 0.0;
}    
H.write();

Info<< "Reading field modH\n" << endl;
volScalarField modH
(
    IOobject
    (
        "modH",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);
//
forAll(modH,i)
{
    modH[i] = mag(H[i]);
}    
modH.write();


Info<< "Reading field alpha_m\n" << endl;
volScalarField alpha_m
(
    IOobject
    (
        "alpha_m",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

forAll(alpha_m,i)
{
       
    alpha_m[i] = mu0.value() * m.value() * modH[i]/ (Kb.value() * T[i]);
    
}    
alpha_m.write();


Info<< "Reading field M0\n" << endl;
volVectorField M0
(
    IOobject
    (
        "M0",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);
 
forAll(M0,i)
{
    double alpha_mC = alpha_m[i];
    
    
    M0[i][0] = 0.0;
    M0[i][1] = vf.value() * Md.value() * (1.0/(Foam::tanh(alpha_mC)) - 1.0/(alpha_mC));
    M0[i][2] = 0.0;

}    


#include "createPhi.H"


label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell(p, mesh.solutionDict().subDict("PISO"), pRefCell, pRefValue);
mesh.setFluxRequired(p.name());
