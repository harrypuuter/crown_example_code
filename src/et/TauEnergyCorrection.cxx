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
ROOT::RDF::RNode TauEnergyCorrection_et (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = physicsobject::tau::PtCorrection_eleFake(df0, correctionManager, "Tau_pt_ele_corrected", "Tau_pt", "Tau_eta", "Tau_decayMode", "Tau_genPartFlav", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "tau_energy_scale", "DeepTau2017v2p1", "nom", "nom", "nom", "nom");
    auto df2 = physicsobject::tau::PtCorrection_muFake(df1, correctionManager, "Tau_pt_mu_corrected", "Tau_pt_ele_corrected", "Tau_eta", "Tau_decayMode", "Tau_genPartFlav", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "tau_energy_scale", "DeepTau2017v2p1", "nom");
    auto df3 = physicsobject::tau::PtCorrection_genTau(df2, correctionManager, "Tau_pt_corrected", "Tau_pt_mu_corrected", "Tau_eta", "Tau_decayMode", "Tau_genPartFlav", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "tau_energy_scale", "DeepTau2017v2p1", "nom", "nom", "nom", "nom");
    auto df4 = physicsobject::tau::PtCorrection_genTau(df3, correctionManager, "Tau_pt_corrected__tauEs3prong1pizeroDown", "Tau_pt_mu_corrected", "Tau_eta", "Tau_decayMode", "Tau_genPartFlav", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "tau_energy_scale", "DeepTau2017v2p1", "nom", "nom", "nom", "down");
    auto df5 = physicsobject::tau::PtCorrection_genTau(df4, correctionManager, "Tau_pt_corrected__tauEs1prong0pizeroDown", "Tau_pt_mu_corrected", "Tau_eta", "Tau_decayMode", "Tau_genPartFlav", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "tau_energy_scale", "DeepTau2017v2p1", "down", "nom", "nom", "nom");
    auto df6 = physicsobject::tau::PtCorrection_genTau(df5, correctionManager, "Tau_pt_corrected__tauEs3prong1pizeroUp", "Tau_pt_mu_corrected", "Tau_eta", "Tau_decayMode", "Tau_genPartFlav", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "tau_energy_scale", "DeepTau2017v2p1", "nom", "nom", "nom", "up");
    auto df7 = physicsobject::tau::PtCorrection_genTau(df6, correctionManager, "Tau_pt_corrected__tauEs1prong1pizeroDown", "Tau_pt_mu_corrected", "Tau_eta", "Tau_decayMode", "Tau_genPartFlav", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "tau_energy_scale", "DeepTau2017v2p1", "nom", "down", "nom", "nom");
    auto df8 = physicsobject::tau::PtCorrection_genTau(df7, correctionManager, "Tau_pt_corrected__tauEs1prong1pizeroUp", "Tau_pt_mu_corrected", "Tau_eta", "Tau_decayMode", "Tau_genPartFlav", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "tau_energy_scale", "DeepTau2017v2p1", "nom", "up", "nom", "nom");
    auto df9 = physicsobject::tau::PtCorrection_genTau(df8, correctionManager, "Tau_pt_corrected__tauEs1prong0pizeroUp", "Tau_pt_mu_corrected", "Tau_eta", "Tau_decayMode", "Tau_genPartFlav", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "tau_energy_scale", "DeepTau2017v2p1", "up", "nom", "nom", "nom");
    auto df10 = physicsobject::tau::PtCorrection_genTau(df9, correctionManager, "Tau_pt_corrected__tauEs3prong0pizeroDown", "Tau_pt_mu_corrected", "Tau_eta", "Tau_decayMode", "Tau_genPartFlav", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "tau_energy_scale", "DeepTau2017v2p1", "nom", "nom", "down", "nom");
    auto df11 = physicsobject::tau::PtCorrection_genTau(df10, correctionManager, "Tau_pt_corrected__tauEs3prong0pizeroUp", "Tau_pt_mu_corrected", "Tau_eta", "Tau_decayMode", "Tau_genPartFlav", "data/jsonpog-integration/POG/TAU/2018_UL/tau.json.gz", "tau_energy_scale", "DeepTau2017v2p1", "nom", "nom", "up", "nom");
    auto df12 = physicsobject::ObjectMassCorrectionWithPt(df11, "Tau_mass_corrected", "Tau_mass", "Tau_pt", "Tau_pt_corrected");
    auto df13 = physicsobject::ObjectMassCorrectionWithPt(df12, "Tau_mass_corrected__tauEs3prong1pizeroDown", "Tau_mass", "Tau_pt", "Tau_pt_corrected__tauEs3prong1pizeroDown");
    auto df14 = physicsobject::ObjectMassCorrectionWithPt(df13, "Tau_mass_corrected__tauEs1prong0pizeroDown", "Tau_mass", "Tau_pt", "Tau_pt_corrected__tauEs1prong0pizeroDown");
    auto df15 = physicsobject::ObjectMassCorrectionWithPt(df14, "Tau_mass_corrected__tauEs3prong1pizeroUp", "Tau_mass", "Tau_pt", "Tau_pt_corrected__tauEs3prong1pizeroUp");
    auto df16 = physicsobject::ObjectMassCorrectionWithPt(df15, "Tau_mass_corrected__tauEs1prong1pizeroDown", "Tau_mass", "Tau_pt", "Tau_pt_corrected__tauEs1prong1pizeroDown");
    auto df17 = physicsobject::ObjectMassCorrectionWithPt(df16, "Tau_mass_corrected__tauEs1prong1pizeroUp", "Tau_mass", "Tau_pt", "Tau_pt_corrected__tauEs1prong1pizeroUp");
    auto df18 = physicsobject::ObjectMassCorrectionWithPt(df17, "Tau_mass_corrected__tauEs1prong0pizeroUp", "Tau_mass", "Tau_pt", "Tau_pt_corrected__tauEs1prong0pizeroUp");
    auto df19 = physicsobject::ObjectMassCorrectionWithPt(df18, "Tau_mass_corrected__tauEs3prong0pizeroDown", "Tau_mass", "Tau_pt", "Tau_pt_corrected__tauEs3prong0pizeroDown");
    auto df20 = physicsobject::ObjectMassCorrectionWithPt(df19, "Tau_mass_corrected__tauEs3prong0pizeroUp", "Tau_mass", "Tau_pt", "Tau_pt_corrected__tauEs3prong0pizeroUp");
    return df20;

}
