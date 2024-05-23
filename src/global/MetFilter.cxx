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
ROOT::RDF::RNode MetFilter_global (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = metfilter::ApplyMetFilter(df0, "Flag_goodVertices", "Flag_goodVertices");
    auto df2 = metfilter::ApplyMetFilter(df1, "Flag_globalSuperTightHalo2016Filter", "Flag_globalSuperTightHalo2016Filter");
    auto df3 = metfilter::ApplyMetFilter(df2, "Flag_HBHENoiseFilter", "Flag_HBHENoiseFilter");
    auto df4 = metfilter::ApplyMetFilter(df3, "Flag_HBHENoiseIsoFilter", "Flag_HBHENoiseIsoFilter");
    auto df5 = metfilter::ApplyMetFilter(df4, "Flag_EcalDeadCellTriggerPrimitiveFilter", "Flag_EcalDeadCellTriggerPrimitiveFilter");
    auto df6 = metfilter::ApplyMetFilter(df5, "Flag_BadPFMuonFilter", "Flag_BadPFMuonFilter");
    auto df7 = metfilter::ApplyMetFilter(df6, "Flag_BadPFMuonDzFilter", "Flag_BadPFMuonDzFilter");
    auto df8 = metfilter::ApplyMetFilter(df7, "Flag_eeBadScFilter", "Flag_eeBadScFilter");
    auto df9 = metfilter::ApplyMetFilter(df8, "Flag_ecalBadCalibFilter", "Flag_ecalBadCalibFilter");
    return df9;

}
