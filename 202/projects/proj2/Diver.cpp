#include "Diver.h"

//constructor -- DEFAULT
Diver::Diver(){
  m_myName = "Joe";
  m_numMaterials = 0;
}
//constructor -- WITH NAME
Diver::Diver(string name){
  SetName("Diver");
  m_numMaterials = 0;
}

//Functions

//GetName
string Diver::GetName(){
  return m_myName;
}

//SetName
void Diver::SetName(string name){
  m_myName = name;
}

//DisplayMaterials
void Diver::DisplayMaterials(){
  for(int i = 0; i < m_numMaterials; i++){
    cout << i+1 << "." << m_myMaterials[i].m_name << " "
	 << m_myMaterials[i].m_quantity << endl;
  }  
}

//CheckMaterial(Material material)
int Diver::CheckMaterial(Material material){
  for(int i = 0; i < m_numMaterials; i++){
    if(m_myMaterials[i].m_name == material.m_name)
      return i;
  }
  return -1;
}

//AddMaterial
void Diver::AddMaterial(Material m){
  m_myMaterials[m_numMaterials] = Material(m.m_name, m.m_type, m.m_material1,
    m.m_material2, m.m_quantity, m.m_depth);
  m_numMaterials++;
}

//IncrementQuantity
void Diver::IncrementQuantity(Material m){
  for(int i = 0; i < m_numMaterials; i++){
    if(m_myMaterials[i].m_name == m.m_name)
      m_myMaterials[i].m_quantity++;
  }
}

//DecrementQuantity
bool Diver::DecrementQuantity(Material m){
    for(int i = 0; i < m_numMaterials; i++){
        if(m_myMaterials[i].m_name == m.m_name and m_myMaterials[i].m_quantity != 0){
            m_myMaterials[i].m_quantity--;
            return true;
        }
    }
    return false;
}

//CheckQuantity
bool Diver::CheckQuantity(Material m1, Material m2){
  if((CheckMaterial(m1) == CheckMaterial(m2) or                                                                  
     (m_myMaterials[CheckMaterial(m1)].m_quantity >= 1 and
      m_myMaterials[CheckMaterial(m2)].m_quantity >= 1)){
        return true;
    }

    return false;
}

//GetMaterial
Material Diver::GetMaterial(int x){
  return m_myMaterials[x];
}

//CalcDepth
int Diver::CalcDepth(){
  int score = 0;
  for(int i = 0; i < m_numMaterials; i++){
    score = m_myMaterials[i].m_depth;
  }
  return score;
}
