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
ROOT::RDF::RNode ElElGenPairQuantities_ee (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = ditau_pairselection::buildgenpair(df0, "dileptonpair", "Electron_genPartIdx", "Electron_genPartIdx", "gen_dileptonpair");
    auto df2 = ditau_pairselection::buildgenpair(df1, "dileptonpair__eleEsResoDown", "Electron_genPartIdx", "Electron_genPartIdx", "gen_dileptonpair__eleEsResoDown");
    auto df3 = ditau_pairselection::buildgenpair(df2, "dileptonpair__eleEsScaleUp", "Electron_genPartIdx", "Electron_genPartIdx", "gen_dileptonpair__eleEsScaleUp");
    auto df4 = ditau_pairselection::buildgenpair(df3, "dileptonpair__eleEsResoUp", "Electron_genPartIdx", "Electron_genPartIdx", "gen_dileptonpair__eleEsResoUp");
    auto df5 = ditau_pairselection::buildgenpair(df4, "dileptonpair__eleEsScaleDown", "Electron_genPartIdx", "Electron_genPartIdx", "gen_dileptonpair__eleEsScaleDown");
    auto df6 = lorentzvectors::build(df5, {"gen_dileptonpair","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1");
    auto df7 = lorentzvectors::build(df6, {"gen_dileptonpair__eleEsResoDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__eleEsResoDown");
    auto df8 = lorentzvectors::build(df7, {"gen_dileptonpair__eleEsScaleUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__eleEsScaleUp");
    auto df9 = lorentzvectors::build(df8, {"gen_dileptonpair__eleEsResoUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__eleEsResoUp");
    auto df10 = lorentzvectors::build(df9, {"gen_dileptonpair__eleEsScaleDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 0, "gen_p4_1__eleEsScaleDown");
    auto df11 = lorentzvectors::build(df10, {"gen_dileptonpair","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2");
    auto df12 = lorentzvectors::build(df11, {"gen_dileptonpair__eleEsResoDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__eleEsResoDown");
    auto df13 = lorentzvectors::build(df12, {"gen_dileptonpair__eleEsScaleUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__eleEsScaleUp");
    auto df14 = lorentzvectors::build(df13, {"gen_dileptonpair__eleEsResoUp","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__eleEsResoUp");
    auto df15 = lorentzvectors::build(df14, {"gen_dileptonpair__eleEsScaleDown","GenPart_pt","GenPart_eta","GenPart_phi","GenPart_mass"}, 1, "gen_p4_2__eleEsScaleDown");
    auto df16 = quantities::pt(df15, "gen_pt_1", "gen_p4_1");
    auto df17 = quantities::pt(df16, "gen_pt_1__eleEsResoDown", "gen_p4_1__eleEsResoDown");
    auto df18 = quantities::pt(df17, "gen_pt_1__eleEsScaleUp", "gen_p4_1__eleEsScaleUp");
    auto df19 = quantities::pt(df18, "gen_pt_1__eleEsResoUp", "gen_p4_1__eleEsResoUp");
    auto df20 = quantities::pt(df19, "gen_pt_1__eleEsScaleDown", "gen_p4_1__eleEsScaleDown");
    auto df21 = quantities::eta(df20, "gen_eta_1", "gen_p4_1");
    auto df22 = quantities::eta(df21, "gen_eta_1__eleEsResoDown", "gen_p4_1__eleEsResoDown");
    auto df23 = quantities::eta(df22, "gen_eta_1__eleEsScaleUp", "gen_p4_1__eleEsScaleUp");
    auto df24 = quantities::eta(df23, "gen_eta_1__eleEsResoUp", "gen_p4_1__eleEsResoUp");
    auto df25 = quantities::eta(df24, "gen_eta_1__eleEsScaleDown", "gen_p4_1__eleEsScaleDown");
    auto df26 = quantities::phi(df25, "gen_phi_1", "gen_p4_1");
    auto df27 = quantities::phi(df26, "gen_phi_1__eleEsResoDown", "gen_p4_1__eleEsResoDown");
    auto df28 = quantities::phi(df27, "gen_phi_1__eleEsScaleUp", "gen_p4_1__eleEsScaleUp");
    auto df29 = quantities::phi(df28, "gen_phi_1__eleEsResoUp", "gen_p4_1__eleEsResoUp");
    auto df30 = quantities::phi(df29, "gen_phi_1__eleEsScaleDown", "gen_p4_1__eleEsScaleDown");
    auto df31 = quantities::mass(df30, "gen_mass_1", "gen_p4_1");
    auto df32 = quantities::mass(df31, "gen_mass_1__eleEsResoDown", "gen_p4_1__eleEsResoDown");
    auto df33 = quantities::mass(df32, "gen_mass_1__eleEsScaleUp", "gen_p4_1__eleEsScaleUp");
    auto df34 = quantities::mass(df33, "gen_mass_1__eleEsResoUp", "gen_p4_1__eleEsResoUp");
    auto df35 = quantities::mass(df34, "gen_mass_1__eleEsScaleDown", "gen_p4_1__eleEsScaleDown");
    auto df36 = quantities::pdgid(df35, "gen_pdgid_1", 0, "gen_dileptonpair", "GenPart_pdgId");
    auto df37 = quantities::pdgid(df36, "gen_pdgid_1__eleEsResoDown", 0, "gen_dileptonpair__eleEsResoDown", "GenPart_pdgId");
    auto df38 = quantities::pdgid(df37, "gen_pdgid_1__eleEsScaleUp", 0, "gen_dileptonpair__eleEsScaleUp", "GenPart_pdgId");
    auto df39 = quantities::pdgid(df38, "gen_pdgid_1__eleEsResoUp", 0, "gen_dileptonpair__eleEsResoUp", "GenPart_pdgId");
    auto df40 = quantities::pdgid(df39, "gen_pdgid_1__eleEsScaleDown", 0, "gen_dileptonpair__eleEsScaleDown", "GenPart_pdgId");
    auto df41 = quantities::pt(df40, "gen_pt_2", "gen_p4_2");
    auto df42 = quantities::pt(df41, "gen_pt_2__eleEsResoDown", "gen_p4_2__eleEsResoDown");
    auto df43 = quantities::pt(df42, "gen_pt_2__eleEsScaleUp", "gen_p4_2__eleEsScaleUp");
    auto df44 = quantities::pt(df43, "gen_pt_2__eleEsResoUp", "gen_p4_2__eleEsResoUp");
    auto df45 = quantities::pt(df44, "gen_pt_2__eleEsScaleDown", "gen_p4_2__eleEsScaleDown");
    auto df46 = quantities::eta(df45, "gen_eta_2", "gen_p4_2");
    auto df47 = quantities::eta(df46, "gen_eta_2__eleEsResoDown", "gen_p4_2__eleEsResoDown");
    auto df48 = quantities::eta(df47, "gen_eta_2__eleEsScaleUp", "gen_p4_2__eleEsScaleUp");
    auto df49 = quantities::eta(df48, "gen_eta_2__eleEsResoUp", "gen_p4_2__eleEsResoUp");
    auto df50 = quantities::eta(df49, "gen_eta_2__eleEsScaleDown", "gen_p4_2__eleEsScaleDown");
    auto df51 = quantities::phi(df50, "gen_phi_2", "gen_p4_2");
    auto df52 = quantities::phi(df51, "gen_phi_2__eleEsResoDown", "gen_p4_2__eleEsResoDown");
    auto df53 = quantities::phi(df52, "gen_phi_2__eleEsScaleUp", "gen_p4_2__eleEsScaleUp");
    auto df54 = quantities::phi(df53, "gen_phi_2__eleEsResoUp", "gen_p4_2__eleEsResoUp");
    auto df55 = quantities::phi(df54, "gen_phi_2__eleEsScaleDown", "gen_p4_2__eleEsScaleDown");
    auto df56 = quantities::mass(df55, "gen_mass_2", "gen_p4_2");
    auto df57 = quantities::mass(df56, "gen_mass_2__eleEsResoDown", "gen_p4_2__eleEsResoDown");
    auto df58 = quantities::mass(df57, "gen_mass_2__eleEsScaleUp", "gen_p4_2__eleEsScaleUp");
    auto df59 = quantities::mass(df58, "gen_mass_2__eleEsResoUp", "gen_p4_2__eleEsResoUp");
    auto df60 = quantities::mass(df59, "gen_mass_2__eleEsScaleDown", "gen_p4_2__eleEsScaleDown");
    auto df61 = quantities::pdgid(df60, "gen_pdgid_2", 1, "gen_dileptonpair", "GenPart_pdgId");
    auto df62 = quantities::pdgid(df61, "gen_pdgid_2__eleEsResoDown", 1, "gen_dileptonpair__eleEsResoDown", "GenPart_pdgId");
    auto df63 = quantities::pdgid(df62, "gen_pdgid_2__eleEsScaleUp", 1, "gen_dileptonpair__eleEsScaleUp", "GenPart_pdgId");
    auto df64 = quantities::pdgid(df63, "gen_pdgid_2__eleEsResoUp", 1, "gen_dileptonpair__eleEsResoUp", "GenPart_pdgId");
    auto df65 = quantities::pdgid(df64, "gen_pdgid_2__eleEsScaleDown", 1, "gen_dileptonpair__eleEsScaleDown", "GenPart_pdgId");
    auto df66 = quantities::m_vis(df65, "gen_m_vis", {"gen_p4_1","gen_p4_2"});
    auto df67 = quantities::m_vis(df66, "gen_m_vis__eleEsResoDown", {"gen_p4_1__eleEsResoDown","gen_p4_2__eleEsResoDown"});
    auto df68 = quantities::m_vis(df67, "gen_m_vis__eleEsScaleUp", {"gen_p4_1__eleEsScaleUp","gen_p4_2__eleEsScaleUp"});
    auto df69 = quantities::m_vis(df68, "gen_m_vis__eleEsResoUp", {"gen_p4_1__eleEsResoUp","gen_p4_2__eleEsResoUp"});
    auto df70 = quantities::m_vis(df69, "gen_m_vis__eleEsScaleDown", {"gen_p4_1__eleEsScaleDown","gen_p4_2__eleEsScaleDown"});
    return df70;

}
