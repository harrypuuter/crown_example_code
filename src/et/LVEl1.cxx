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
ROOT::RDF::RNode LVEl1_et (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = lorentzvectors::build(df0, {"dileptonpair","Electron_pt_corrected","Electron_eta","Electron_phi","Electron_mass"}, 0, "p4_1");
    auto df2 = lorentzvectors::build(df1, {"dileptonpair__eleEsResoDown","Electron_pt_corrected__eleEsResoDown","Electron_eta","Electron_phi","Electron_mass"}, 0, "p4_1__eleEsResoDown");
    auto df3 = lorentzvectors::build(df2, {"dileptonpair__eleEsScaleUp","Electron_pt_corrected__eleEsScaleUp","Electron_eta","Electron_phi","Electron_mass"}, 0, "p4_1__eleEsScaleUp");
    auto df4 = lorentzvectors::build(df3, {"dileptonpair__eleEsResoUp","Electron_pt_corrected__eleEsResoUp","Electron_eta","Electron_phi","Electron_mass"}, 0, "p4_1__eleEsResoUp");
    auto df5 = lorentzvectors::build(df4, {"dileptonpair__eleEsScaleDown","Electron_pt_corrected__eleEsScaleDown","Electron_eta","Electron_phi","Electron_mass"}, 0, "p4_1__eleEsScaleDown");
    return df5;

}
