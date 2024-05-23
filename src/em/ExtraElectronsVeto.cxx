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
ROOT::RDF::RNode ExtraElectronsVeto_em (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = physicsobject::LeptonVetoFlag(df0, "extraelec_veto", "veto_electrons_mask");
    auto df2 = physicsobject::LeptonVetoFlag(df1, "extraelec_veto__eleEsResoDown", "veto_electrons_mask__eleEsResoDown");
    auto df3 = physicsobject::LeptonVetoFlag(df2, "extraelec_veto__eleEsScaleUp", "veto_electrons_mask__eleEsScaleUp");
    auto df4 = physicsobject::LeptonVetoFlag(df3, "extraelec_veto__eleEsResoUp", "veto_electrons_mask__eleEsResoUp");
    auto df5 = physicsobject::LeptonVetoFlag(df4, "extraelec_veto__eleEsScaleDown", "veto_electrons_mask__eleEsScaleDown");
    return df5;

}
