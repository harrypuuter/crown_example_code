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
ROOT::RDF::RNode ElElPairQuantities_ee (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = quantities::pt(df0, "pt_1", "p4_1");
    auto df2 = quantities::pt(df1, "pt_1__eleEsResoDown", "p4_1__eleEsResoDown");
    auto df3 = quantities::pt(df2, "pt_1__eleEsScaleUp", "p4_1__eleEsScaleUp");
    auto df4 = quantities::pt(df3, "pt_1__eleEsResoUp", "p4_1__eleEsResoUp");
    auto df5 = quantities::pt(df4, "pt_1__eleEsScaleDown", "p4_1__eleEsScaleDown");
    auto df6 = quantities::eta(df5, "eta_1", "p4_1");
    auto df7 = quantities::eta(df6, "eta_1__eleEsResoDown", "p4_1__eleEsResoDown");
    auto df8 = quantities::eta(df7, "eta_1__eleEsScaleUp", "p4_1__eleEsScaleUp");
    auto df9 = quantities::eta(df8, "eta_1__eleEsResoUp", "p4_1__eleEsResoUp");
    auto df10 = quantities::eta(df9, "eta_1__eleEsScaleDown", "p4_1__eleEsScaleDown");
    auto df11 = quantities::phi(df10, "phi_1", "p4_1");
    auto df12 = quantities::phi(df11, "phi_1__eleEsResoDown", "p4_1__eleEsResoDown");
    auto df13 = quantities::phi(df12, "phi_1__eleEsScaleUp", "p4_1__eleEsScaleUp");
    auto df14 = quantities::phi(df13, "phi_1__eleEsResoUp", "p4_1__eleEsResoUp");
    auto df15 = quantities::phi(df14, "phi_1__eleEsScaleDown", "p4_1__eleEsScaleDown");
    auto df16 = quantities::mass(df15, "mass_1", "p4_1");
    auto df17 = quantities::mass(df16, "mass_1__eleEsResoDown", "p4_1__eleEsResoDown");
    auto df18 = quantities::mass(df17, "mass_1__eleEsScaleUp", "p4_1__eleEsScaleUp");
    auto df19 = quantities::mass(df18, "mass_1__eleEsResoUp", "p4_1__eleEsResoUp");
    auto df20 = quantities::mass(df19, "mass_1__eleEsScaleDown", "p4_1__eleEsScaleDown");
    auto df21 = quantities::dxy(df20, "dxy_1", 0, "dileptonpair", "Electron_dxy");
    auto df22 = quantities::dxy(df21, "dxy_1__eleEsResoDown", 0, "dileptonpair__eleEsResoDown", "Electron_dxy");
    auto df23 = quantities::dxy(df22, "dxy_1__eleEsScaleUp", 0, "dileptonpair__eleEsScaleUp", "Electron_dxy");
    auto df24 = quantities::dxy(df23, "dxy_1__eleEsResoUp", 0, "dileptonpair__eleEsResoUp", "Electron_dxy");
    auto df25 = quantities::dxy(df24, "dxy_1__eleEsScaleDown", 0, "dileptonpair__eleEsScaleDown", "Electron_dxy");
    auto df26 = quantities::dz(df25, "dz_1", 0, "dileptonpair", "Electron_dz");
    auto df27 = quantities::dz(df26, "dz_1__eleEsResoDown", 0, "dileptonpair__eleEsResoDown", "Electron_dz");
    auto df28 = quantities::dz(df27, "dz_1__eleEsScaleUp", 0, "dileptonpair__eleEsScaleUp", "Electron_dz");
    auto df29 = quantities::dz(df28, "dz_1__eleEsResoUp", 0, "dileptonpair__eleEsResoUp", "Electron_dz");
    auto df30 = quantities::dz(df29, "dz_1__eleEsScaleDown", 0, "dileptonpair__eleEsScaleDown", "Electron_dz");
    auto df31 = quantities::charge(df30, "q_1", 0, "dileptonpair", "Electron_charge");
    auto df32 = quantities::charge(df31, "q_1__eleEsResoDown", 0, "dileptonpair__eleEsResoDown", "Electron_charge");
    auto df33 = quantities::charge(df32, "q_1__eleEsScaleUp", 0, "dileptonpair__eleEsScaleUp", "Electron_charge");
    auto df34 = quantities::charge(df33, "q_1__eleEsResoUp", 0, "dileptonpair__eleEsResoUp", "Electron_charge");
    auto df35 = quantities::charge(df34, "q_1__eleEsScaleDown", 0, "dileptonpair__eleEsScaleDown", "Electron_charge");
    auto df36 = quantities::isolation(df35, "iso_1", 0, "dileptonpair", "Electron_pfRelIso03_all");
    auto df37 = quantities::isolation(df36, "iso_1__eleEsResoDown", 0, "dileptonpair__eleEsResoDown", "Electron_pfRelIso03_all");
    auto df38 = quantities::isolation(df37, "iso_1__eleEsScaleUp", 0, "dileptonpair__eleEsScaleUp", "Electron_pfRelIso03_all");
    auto df39 = quantities::isolation(df38, "iso_1__eleEsResoUp", 0, "dileptonpair__eleEsResoUp", "Electron_pfRelIso03_all");
    auto df40 = quantities::isolation(df39, "iso_1__eleEsScaleDown", 0, "dileptonpair__eleEsScaleDown", "Electron_pfRelIso03_all");
    auto df41 = quantities::pt(df40, "pt_2", "p4_2");
    auto df42 = quantities::pt(df41, "pt_2__eleEsResoDown", "p4_2__eleEsResoDown");
    auto df43 = quantities::pt(df42, "pt_2__eleEsScaleUp", "p4_2__eleEsScaleUp");
    auto df44 = quantities::pt(df43, "pt_2__eleEsResoUp", "p4_2__eleEsResoUp");
    auto df45 = quantities::pt(df44, "pt_2__eleEsScaleDown", "p4_2__eleEsScaleDown");
    auto df46 = quantities::eta(df45, "eta_2", "p4_2");
    auto df47 = quantities::eta(df46, "eta_2__eleEsResoDown", "p4_2__eleEsResoDown");
    auto df48 = quantities::eta(df47, "eta_2__eleEsScaleUp", "p4_2__eleEsScaleUp");
    auto df49 = quantities::eta(df48, "eta_2__eleEsResoUp", "p4_2__eleEsResoUp");
    auto df50 = quantities::eta(df49, "eta_2__eleEsScaleDown", "p4_2__eleEsScaleDown");
    auto df51 = quantities::phi(df50, "phi_2", "p4_2");
    auto df52 = quantities::phi(df51, "phi_2__eleEsResoDown", "p4_2__eleEsResoDown");
    auto df53 = quantities::phi(df52, "phi_2__eleEsScaleUp", "p4_2__eleEsScaleUp");
    auto df54 = quantities::phi(df53, "phi_2__eleEsResoUp", "p4_2__eleEsResoUp");
    auto df55 = quantities::phi(df54, "phi_2__eleEsScaleDown", "p4_2__eleEsScaleDown");
    auto df56 = quantities::mass(df55, "mass_2", "p4_2");
    auto df57 = quantities::mass(df56, "mass_2__eleEsResoDown", "p4_2__eleEsResoDown");
    auto df58 = quantities::mass(df57, "mass_2__eleEsScaleUp", "p4_2__eleEsScaleUp");
    auto df59 = quantities::mass(df58, "mass_2__eleEsResoUp", "p4_2__eleEsResoUp");
    auto df60 = quantities::mass(df59, "mass_2__eleEsScaleDown", "p4_2__eleEsScaleDown");
    auto df61 = quantities::dxy(df60, "dxy_2", 1, "dileptonpair", "Electron_dxy");
    auto df62 = quantities::dxy(df61, "dxy_2__eleEsResoDown", 1, "dileptonpair__eleEsResoDown", "Electron_dxy");
    auto df63 = quantities::dxy(df62, "dxy_2__eleEsScaleUp", 1, "dileptonpair__eleEsScaleUp", "Electron_dxy");
    auto df64 = quantities::dxy(df63, "dxy_2__eleEsResoUp", 1, "dileptonpair__eleEsResoUp", "Electron_dxy");
    auto df65 = quantities::dxy(df64, "dxy_2__eleEsScaleDown", 1, "dileptonpair__eleEsScaleDown", "Electron_dxy");
    auto df66 = quantities::dz(df65, "dz_2", 1, "dileptonpair", "Electron_dz");
    auto df67 = quantities::dz(df66, "dz_2__eleEsResoDown", 1, "dileptonpair__eleEsResoDown", "Electron_dz");
    auto df68 = quantities::dz(df67, "dz_2__eleEsScaleUp", 1, "dileptonpair__eleEsScaleUp", "Electron_dz");
    auto df69 = quantities::dz(df68, "dz_2__eleEsResoUp", 1, "dileptonpair__eleEsResoUp", "Electron_dz");
    auto df70 = quantities::dz(df69, "dz_2__eleEsScaleDown", 1, "dileptonpair__eleEsScaleDown", "Electron_dz");
    auto df71 = quantities::charge(df70, "q_2", 1, "dileptonpair", "Electron_charge");
    auto df72 = quantities::charge(df71, "q_2__eleEsResoDown", 1, "dileptonpair__eleEsResoDown", "Electron_charge");
    auto df73 = quantities::charge(df72, "q_2__eleEsScaleUp", 1, "dileptonpair__eleEsScaleUp", "Electron_charge");
    auto df74 = quantities::charge(df73, "q_2__eleEsResoUp", 1, "dileptonpair__eleEsResoUp", "Electron_charge");
    auto df75 = quantities::charge(df74, "q_2__eleEsScaleDown", 1, "dileptonpair__eleEsScaleDown", "Electron_charge");
    auto df76 = quantities::isolation(df75, "iso_2", 1, "dileptonpair", "Electron_pfRelIso03_all");
    auto df77 = quantities::isolation(df76, "iso_2__eleEsResoDown", 1, "dileptonpair__eleEsResoDown", "Electron_pfRelIso03_all");
    auto df78 = quantities::isolation(df77, "iso_2__eleEsScaleUp", 1, "dileptonpair__eleEsScaleUp", "Electron_pfRelIso03_all");
    auto df79 = quantities::isolation(df78, "iso_2__eleEsResoUp", 1, "dileptonpair__eleEsResoUp", "Electron_pfRelIso03_all");
    auto df80 = quantities::isolation(df79, "iso_2__eleEsScaleDown", 1, "dileptonpair__eleEsScaleDown", "Electron_pfRelIso03_all");
    auto df81 = basefunctions::DefineQuantity(df80, "tau_decaymode_1", -1);
    auto df82 = basefunctions::DefineQuantity(df81, "tau_decaymode_2", -1);
    auto df83 = quantities::m_vis(df82, "m_vis", {"p4_1","p4_2"});
    auto df84 = quantities::m_vis(df83, "m_vis__eleEsResoDown", {"p4_1__eleEsResoDown","p4_2__eleEsResoDown"});
    auto df85 = quantities::m_vis(df84, "m_vis__eleEsScaleUp", {"p4_1__eleEsScaleUp","p4_2__eleEsScaleUp"});
    auto df86 = quantities::m_vis(df85, "m_vis__eleEsResoUp", {"p4_1__eleEsResoUp","p4_2__eleEsResoUp"});
    auto df87 = quantities::m_vis(df86, "m_vis__eleEsScaleDown", {"p4_1__eleEsScaleDown","p4_2__eleEsScaleDown"});
    auto df88 = quantities::pt_vis(df87, "pt_vis", {"p4_1","p4_2"});
    auto df89 = quantities::pt_vis(df88, "pt_vis__eleEsResoDown", {"p4_1__eleEsResoDown","p4_2__eleEsResoDown"});
    auto df90 = quantities::pt_vis(df89, "pt_vis__eleEsScaleUp", {"p4_1__eleEsScaleUp","p4_2__eleEsScaleUp"});
    auto df91 = quantities::pt_vis(df90, "pt_vis__eleEsResoUp", {"p4_1__eleEsResoUp","p4_2__eleEsResoUp"});
    auto df92 = quantities::pt_vis(df91, "pt_vis__eleEsScaleDown", {"p4_1__eleEsScaleDown","p4_2__eleEsScaleDown"});
    auto df93 = quantities::deltaR(df92, "deltaR_ditaupair", "p4_1", "p4_2");
    auto df94 = quantities::deltaR(df93, "deltaR_ditaupair__eleEsResoDown", "p4_1__eleEsResoDown", "p4_2__eleEsResoDown");
    auto df95 = quantities::deltaR(df94, "deltaR_ditaupair__eleEsScaleUp", "p4_1__eleEsScaleUp", "p4_2__eleEsScaleUp");
    auto df96 = quantities::deltaR(df95, "deltaR_ditaupair__eleEsResoUp", "p4_1__eleEsResoUp", "p4_2__eleEsResoUp");
    auto df97 = quantities::deltaR(df96, "deltaR_ditaupair__eleEsScaleDown", "p4_1__eleEsScaleDown", "p4_2__eleEsScaleDown");
    return df97;

}
