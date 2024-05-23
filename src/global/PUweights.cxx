#include "ROOT/RDataFrame.hxx"
#include "ROOT/RDFHelpers.hxx"
#include "RooTrace.h"
#include "TStopwatch.h"
#include <ROOT/RLogger.hxx>
#include "include/utility/Logger.hxx"
#include <TFile.h>
#include <TMap.h>
#include <filesystem>
#include <TObjString.h>
#include <TTree.h>
#include <TVector.h>
#include "onnxruntime_cxx_api.h"
#include <regex>
#include <string>
#include "include/utility/OnnxSessionManager.hxx"
#include "include/utility/CorrectionManager.hxx"
#include "include/genparticles.hxx"
#include "include/htxs.hxx"
#include "include/jets.hxx"
#include "include/lorentzvectors.hxx"
#include "include/met.hxx"
#include "include/ml.hxx"
#include "include/metfilter.hxx"
#include "include/pairselection.hxx"
#include "include/tripleselection.hxx"
#include "include/physicsobjects.hxx"
#include "include/quantities.hxx"
#include "include/reweighting.hxx"
#include "include/scalefactors.hxx"
#include "include/topreco.hxx"
#include "include/triggers.hxx"
#include "include/fakefactors.hxx"
ROOT::RDF::RNode PUweights_global (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = reweighting::puweights(df0, correctionManager, "puweight", "Pileup_nTrueInt", "data/jsonpog-integration/POG/LUM/2018_UL/puWeights.json.gz", "Collisions18_UltraLegacy_goldenJSON", "nominal");
    auto df2 = reweighting::puweights(df1, correctionManager, "puweight__PileUpUp", "Pileup_nTrueInt", "data/jsonpog-integration/POG/LUM/2018_UL/puWeights.json.gz", "Collisions18_UltraLegacy_goldenJSON", "up");
    auto df3 = reweighting::puweights(df2, correctionManager, "puweight__PileUpDown", "Pileup_nTrueInt", "data/jsonpog-integration/POG/LUM/2018_UL/puWeights.json.gz", "Collisions18_UltraLegacy_goldenJSON", "down");
    return df3;

}
