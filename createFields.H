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
*/
// Vector fields

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
/*
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
*/
#include "createPhi.H"


label pRefCell = 0;
scalar pRefValue = 0.0;
setRefCell(p, mesh.solutionDict().subDict("PISO"), pRefCell, pRefValue);
mesh.setFluxRequired(p.name());
