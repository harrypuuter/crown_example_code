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
ROOT::RDF::RNode ElectronPtCorrectionMC_global (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = physicsobject::electron::PtCorrectionMC(df0, correctionManager, "Electron_pt_corrected", "Electron_pt", "Electron_eta", "Electron_seedGain", "Electron_dEsigmaUp", "Electron_dEsigmaDown", "2018", "nom", "data/electron_energy_scale/2018_UL/EGM_ScaleUnc.json.gz");
    auto df2 = physicsobject::electron::PtCorrectionMC(df1, correctionManager, "Electron_pt_corrected__eleEsResoDown", "Electron_pt", "Electron_eta", "Electron_seedGain", "Electron_dEsigmaUp", "Electron_dEsigmaDown", "2018", "resolutionDown", "data/electron_energy_scale/2018_UL/EGM_ScaleUnc.json.gz");
    auto df3 = physicsobject::electron::PtCorrectionMC(df2, correctionManager, "Electron_pt_corrected__eleEsScaleUp", "Electron_pt", "Electron_eta", "Electron_seedGain", "Electron_dEsigmaUp", "Electron_dEsigmaDown", "2018", "scaleUp", "data/electron_energy_scale/2018_UL/EGM_ScaleUnc.json.gz");
    auto df4 = physicsobject::electron::PtCorrectionMC(df3, correctionManager, "Electron_pt_corrected__eleEsResoUp", "Electron_pt", "Electron_eta", "Electron_seedGain", "Electron_dEsigmaUp", "Electron_dEsigmaDown", "2018", "resolutionUp", "data/electron_energy_scale/2018_UL/EGM_ScaleUnc.json.gz");
    auto df5 = physicsobject::electron::PtCorrectionMC(df4, correctionManager, "Electron_pt_corrected__eleEsScaleDown", "Electron_pt", "Electron_eta", "Electron_seedGain", "Electron_dEsigmaUp", "Electron_dEsigmaDown", "2018", "scaleDown", "data/electron_energy_scale/2018_UL/EGM_ScaleUnc.json.gz");
    return df5;

}
