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
ROOT::RDF::RNode ElElPairSelection_ee (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = ditau_pairselection::elel::PairSelection(df0, {"Electron_pt_corrected","Electron_eta","Electron_phi","Electron_mass","good_electrons_mask"}, "dileptonpair", 0.5);
    auto df2 = ditau_pairselection::elel::PairSelection(df1, {"Electron_pt_corrected__eleEsResoDown","Electron_eta","Electron_phi","Electron_mass","good_electrons_mask__eleEsResoDown"}, "dileptonpair__eleEsResoDown", 0.5);
    auto df3 = ditau_pairselection::elel::PairSelection(df2, {"Electron_pt_corrected__eleEsScaleUp","Electron_eta","Electron_phi","Electron_mass","good_electrons_mask__eleEsScaleUp"}, "dileptonpair__eleEsScaleUp", 0.5);
    auto df4 = ditau_pairselection::elel::PairSelection(df3, {"Electron_pt_corrected__eleEsResoUp","Electron_eta","Electron_phi","Electron_mass","good_electrons_mask__eleEsResoUp"}, "dileptonpair__eleEsResoUp", 0.5);
    auto df5 = ditau_pairselection::elel::PairSelection(df4, {"Electron_pt_corrected__eleEsScaleDown","Electron_eta","Electron_phi","Electron_mass","good_electrons_mask__eleEsScaleDown"}, "dileptonpair__eleEsScaleDown", 0.5);
    return df5;

}
