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
ROOT::RDF::RNode MetBasics_global (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = lorentzvectors::buildMet(df0, "MET_pt", "MET_phi", "pfmet_p4");
    auto df2 = lorentzvectors::buildMet(df1, "PuppiMET_pt", "PuppiMET_phi", "met_p4");
    auto df3 = lorentzvectors::buildMet(df2, "PuppiMET_ptUnclusteredDown", "PuppiMET_phiUnclusteredDown", "met_p4__metUnclusteredEnDown");
    auto df4 = lorentzvectors::buildMet(df3, "PuppiMET_ptUnclusteredUp", "PuppiMET_phiUnclusteredUp", "met_p4__metUnclusteredEnUp");
    auto df5 = quantities::pt(df4, "met_uncorrected", "met_p4");
    auto df6 = quantities::pt(df5, "met_uncorrected__metUnclusteredEnDown", "met_p4__metUnclusteredEnDown");
    auto df7 = quantities::pt(df6, "met_uncorrected__metUnclusteredEnUp", "met_p4__metUnclusteredEnUp");
    auto df8 = quantities::phi(df7, "metphi_uncorrected", "met_p4");
    auto df9 = quantities::phi(df8, "metphi_uncorrected__metUnclusteredEnDown", "met_p4__metUnclusteredEnDown");
    auto df10 = quantities::phi(df9, "metphi_uncorrected__metUnclusteredEnUp", "met_p4__metUnclusteredEnUp");
    auto df11 = quantities::pt(df10, "pfmet_uncorrected", "pfmet_p4");
    auto df12 = quantities::phi(df11, "pfmetphi_uncorrected", "pfmet_p4");
    auto df13 = basefunctions::rename<float>(df12, "MET_covXX", "metcov00");
    auto df14 = basefunctions::rename<float>(df13, "MET_covXY", "metcov01");
    auto df15 = basefunctions::rename<float>(df14, "MET_covXY", "metcov10");
    auto df16 = basefunctions::rename<float>(df15, "MET_covYY", "metcov11");
    auto df17 = basefunctions::rename<float>(df16, "PuppiMET_sumEt", "metSumEt");
    auto df18 = met::calculateGenBosonVector(df17, "GenPart_pt", "GenPart_eta", "GenPart_phi", "GenPart_mass", "GenPart_pdgId", "GenPart_status", "GenPart_statusFlags", "recoil_genboson_p4_vec", false);
    auto df19 = met::genBosonMass(df18, "genbosonmass", "recoil_genboson_p4_vec");
    return df19;

}
