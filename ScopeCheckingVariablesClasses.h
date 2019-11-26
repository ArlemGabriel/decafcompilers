#ifndef SCOPECHECKINGVARIABLESCLASSES_H_INCLUDED
#define SCOPECHECKINGVARIABLESCLASSES_H_INCLUDED

#include <vector>
#include "stacktables.h"


vector<string> semanticerrorsclasses;
vector<pElementSCH> classattributes;
vector<vector<pElementSCH > > listofclasses;
vector<vector<pElementSCH > > classesattributes;
vector<vector<pElementSCH > > classesmehotds;
/*
bool SearchRepeats(string error){
    bool searchresult = false;
    if(!semanticerrors.empty()){
        for(int i=0;i<=semanticerrors.size()-1;i++){
            if(semanticerrors.at(i)==error){
                searchresult = true;
            }
        }
    }
    return searchresult;
}

void printErrors(){
    if(semanticerrors.empty()){
        cout << "Non errors found";
    }
    else{
        for(int i=0;i<=semanticerrors.size()-1;i++){
            cout << semanticerrors.at(i);
        }
    }


}
void PrintScopes(vector<vector<vector<string> > > listofscopes){
    int positions = listofscopes.size()-1;
    vector<vector<string> > templist;
    for(int y=0;y<=positions;y++){
        templist = listofscopes.at(y);
        int scopepositions = templist.size()-1;
        for(int i =0;i<=scopepositions;i++){
            cout << "Type: " << templist.at(i).at(0)<<"\n";
            cout << "Token: " << templist.at(i).at(1)<<"\n";
            cout << "Value1: " << templist.at(i).at(2)<<"\n";
            cout << "Value2: " << templist.at(i).at(3)<<"\n";
            cout << "_________________________________________________\n";
        }
        cout << "_________________________________________________\n";
    }
    cout << "\n \n";
}

vector<vector<vector<string> > > SearchLocalVariablesClasses(TablesStack tb, string scopevalue){
    int stackpositions = tb.GetStackSize()-1;
    int finalscopeposition;
    int newscopeglobalvalue;
    string finalscopevalue;
    vector<vector<vector<string> > > listscopes;
    vector<vector<string> > tempscope;
    vector<vector<string> > localdecl;
    vector<vector<string> > globaldecl;
    vector<vector<string> > bracestoclose;
    vector<vector<string> > intermediatescopes;
    vector<vector<vector<string> > > globalscopes;

    for(stackpositions;stackpositions>=0;stackpositions--){
        tempscope = tb.GetScope(stackpositions);
        int scopepositions = tempscope.size()-1;
        bool searchEnded = false;
        //cout << "STACKPOSITIONS: " << stackpositions <<"\n";

        for(int i =0;i<=scopepositions;i++){
                /*cout <<"------------------------------------\n";
                cout <<"TYPE: " << tempscope.at(i).at(0) << "\n";
                cout <<"TOKEN: " << tempscope.at(i).at(1) << "\n";
                cout <<"VALUE1: " << tempscope.at(i).at(2) << "\n";
                cout <<"VALUE2: " << tempscope.at(i).at(3) << "\n";
                cout <<"------------------------------------\n";
                if(tempscope.at(i).at(1) == "LBRACE" && tempscope.at(i).at(2)==scopevalue){
                    /*cout <<"Decision Tomada: FINALIZAR BUSQUEDA \n";
                    cout <<"____________________________________\n";

                    finalscopeposition = stackpositions-1;
                    newscopeglobalvalue = stoi(scopevalue)-1;
                    finalscopevalue = to_string(newscopeglobalvalue);
                    /*cout <<"        ////////////////////////////////////\n";
                    cout <<"        TYPE: " << tempscope.at(i).at(0) << "\n";
                    cout <<"        TOKEN: " << tempscope.at(i).at(1) << "\n";
                    cout <<"        VALUE1: " << tempscope.at(i).at(2) << "\n";
                    cout <<"        VALUE2: " << tempscope.at(i).at(3) << "\n";
                    cout <<"        ////////////////////////////////////\n";
                    cout << "       SCOPEVALUE: " << scopevalue << "-----------"<< "\n"
                    //localdecl= tb.GetScope(stackpositions+1);
                    //globaldecl= tb.GetScope(stackpositions-1);
                    searchEnded = true;
                    //cout << "\n----------------------\n";
                   // cout << localdecl.size() << "\n";
                    //cout << globaldecl.size() << "\n";
                   // cout << "----------------------\n";

                    //cout << localdecl.at(0).at(0) << " " << localdecl.at(0).at(1) << " " << localdecl.at(0).at(2) << "\n";
                    //cout << globaldecl.at(0).at(0) << " " << globaldecl.at(0).at(1) << " " << globaldecl.at(0).at(2) << "\n";
                    //cout << localdecl.at(0).at(0) << " " << localdecl.at(0).at(1) << " " << localdecl.at(0).at(2) << "\n";
                    //cout << localdecl.at(1).at(0) << " " << localdecl.at(1).at(1) << " " << localdecl.at(1).at(2) << "\n";

                    //cout << globaldecl.at(0).at(0) << " " << globaldecl.at(0).at(1) << " " << globaldecl.at(0).at(2) << "\n";
                    //cout << globaldecl.at(1).at(0) << " " << globaldecl.at(1).at(1) << " " << globaldecl.at(1).at(2) << "\n";
                    //break;
                }
                if(tempscope.at(i).at(1) == "RBRACE"){
                    /*cout <<"Decision Tomada: INGRESAR OTRO SCOPE PARA IGNORAR \n";
                    cout <<"____________________________________\n";
                    tempscope.at(i).at(1) = "LBRACE";
                    bracestoclose.push_back(tempscope.at(i));
                    tempscope.at(i).at(1) = "RBRACE";
                }
                if(!bracestoclose.empty() && tempscope.at(i).at(1)=="LBRACE"){
                    /*cout <<"Decision Tomada: ELIMINAR UN SCOPE YA VISITADO \n";
                    cout <<"____________________________________\n";
                    int sizebracestoclose = bracestoclose.size()-1;
                    if(tempscope.at(i).at(2)==bracestoclose.at(sizebracestoclose).at(2)){
                        bracestoclose.pop_back();
                    }
                }
                if(bracestoclose.empty() && tempscope.at(i).at(1)=="Exp"){
                    /*cout <<"Decision Tomada: AGREGAR UN SCOPE INTERMEDIO \n";
                    cout <<"____________________________________\n";
                    intermediatescopes.push_back(tempscope.at(i));
                }
                if(bracestoclose.empty() && tempscope.at(i).at(1)=="Variable"){
                    /*cout <<"Decision Tomada: AGREGAR UN SCOPE VARIABLE \n";
                    cout <<"____________________________________\n";
                    localdecl.push_back(tempscope.at(i));
                }
        }
        if(searchEnded==true){
            break;
        }
    }
    //vector<vector<vector<string> > > globalscopevariables = tb.GetStackFromValue(finalscopeposition);
    //globaldecl = SearchGlobalVariablesClasses(globalscopevariables,finalscopevalue);

    listscopes.push_back(localdecl);
    listscopes.push_back(globaldecl);
    listscopes.push_back(intermediatescopes);
    return listscopes;
}

//Elimina aquellos valores que no son asignaciones o expresiones (declaracion de funciones etc)
vector<vector<vector<string> > > DeleteOtherValues(vector<vector<vector<string> > > listofscopes){
    int positions = listofscopes.size()-1;
    vector<vector<vector<string> > > tempscopes;
    vector<vector<string> > oldlist;
    vector<vector<string> > newlist;
    for(int y=0;y<=positions;y++){
        oldlist = listofscopes.at(y);
        int scopepositions = oldlist.size()-1;
        newlist.clear();
        for(int i =0;i<=scopepositions;i++){
            if(oldlist.at(i).at(1)== "Exp" || oldlist.at(i).at(1) == "Variable"){
                newlist.push_back(oldlist.at(i));
            }

        }
        tempscopes.push_back(newlist);
    }
    return tempscopes;
}
vector<vector<vector<string> > > DivideScopes (vector<vector<vector<string> > > listofscopes){
    int positions = listofscopes.size()-1;
    vector<vector<vector<string> > > tempscopes;
    vector<vector<string> > oldlist;
    vector<vector<string> > globalsdecl;
    vector<vector<string> > localsdecl;
    vector<vector<string> > globalsassign;
    vector<vector<string> > localsassign;

    for(int y=0;y<=positions;y++){
        oldlist = listofscopes.at(y);
        int scopepositions = oldlist.size()-1;
        if(y==0){
            for(int i =0;i<=scopepositions;i++){
                if(oldlist.at(i).at(1)== "Exp"){
                    localsassign.push_back(oldlist.at(i));
                }
                if(oldlist.at(i).at(1) == "Variable"){
                    localsdecl.push_back(oldlist.at(i));
                }
            }
        }
        if(y==1){
            for(int i =0;i<=scopepositions;i++){
                if(oldlist.at(i).at(1)== "Exp"){
                    globalsassign.push_back(oldlist.at(i));
                }
                if(oldlist.at(i).at(1) == "Variable"){
                    globalsdecl.push_back(oldlist.at(i));
                }
            }
        }
        if(y==2){
            for(int i =0;i<=scopepositions;i++){
                localsassign.push_back(oldlist.at(i));
            }
        }
        /*for(int i =0;i<=scopepositions;i++){
            if(y==0){
                if(oldlist.at(i).at(1)== "Exp"){
                    localsassign.push_back(oldlist.at(i));
                }
                if(oldlist.at(i).at(1) == "Variable"){
                    localsdecl.push_back(oldlist.at(i));
                }
            }
            if(y==1){
                if(oldlist.at(i).at(1)== "Exp"){
                    globalsassign.push_back(oldlist.at(i));
                }
                if(oldlist.at(i).at(1) == "Variable"){
                    globalsdecl.push_back(oldlist.at(i));
                }
            }
            if(y==2){
                if(oldlist.at(i).at(1)== "Exp"){
                    localsassign.push_back(oldlist.at(i));
                }
            }
        }
    }
    tempscopes.push_back(globalsdecl);
    tempscopes.push_back(localsdecl);
    tempscopes.push_back(globalsassign);
    tempscopes.push_back(localsassign);
    /*cout <<"GLOBALSDECL: " << globalsdecl.size() << "\n";
    cout <<"GLOBALSASSIGN: " << globalsassign.size()<< "\n";
    cout <<"LOCALSDECL: " << localsdecl.size()<< "\n";
    cout <<"LOCALSASSIGN: " << localsassign.size()<< "\n";
    return tempscopes;
}
bool ChekingVariables(vector<vector<vector<string> > > listofscopes){
    int positions = listofscopes.size()-1;
    bool checkingresult = false;
    vector<vector<string> > globalsdecl = listofscopes.at(0);
    vector<vector<string> > localsdecl = listofscopes.at(1);
    vector<vector<string> > globalsassign = listofscopes.at(2);
    vector<vector<string> > localsassign = listofscopes.at(3);
    vector<vector<string> > localtogloblalscope;
    int globalsdeclsize = globalsdecl.size()-1;
    int localsdeclsize = localsdecl.size()-1;
    int globalsassignsize = globalsassign.size()-1;
    int localsassignsize = localsassign.size()-1;
    if(!globalsassign.empty()){
        //cout << "ENTRE A GLOBALASSIGN" << "\n";
        bool variableonscope;
        for(int i=0;i<=globalsassignsize;i++){
            variableonscope = false;
            for(int y=0;y<=globalsdeclsize;y++){
                if(globalsassign.at(i).at(2)==globalsdecl.at(y).at(2)){
                    variableonscope = true;
                    /*cout << "VARIABLE LOCAL ESTA EN EL SCOPE LOCAL\n";
                    cout << "  Valor: " << globalsassign.at(i).at(0) << " " << globalsassign.at(i).at(1) << " " << globalsassign.at(i).at(2) << "\n";
                }
            }
            if(variableonscope==false){
               /* cout << "VARIABLE LOCAL NO ESTA EN EL SCOPE LOCAL\n";
                cout << "  Valor: " << globalsassign.at(i).at(0) << " " << globalsassign.at(i).at(1) << " " << globalsassign.at(i).at(2) << "\n";
            }
        }
    }
    if(!localsassign.empty()){
        bool variableonscope;
        //cout << "ENTRE A LOCALASSIGN" << "\n";
        for(int i=0;i<=localsassignsize;i++){
            variableonscope = false;
            for(int y=0;y<=localsdeclsize;y++){
                if(localsassign.at(i).at(2)==localsdecl.at(y).at(2)){
                    variableonscope = true;
                    /*cout << "ESTA EN EL SCOPE LOCAL\n";
                    cout << "  Valor: " << localsassign.at(i).at(0) << " " << localsassign.at(i).at(1) << " " << localsassign.at(i).at(2) << "\n";
                }
            }
            if(variableonscope==false){
                /*cout << "NO ESTA EN EL SCOPE LOCAL\n";
                cout << "  Valor: " << localsassign.at(i).at(0) << " " << localsassign.at(i).at(1) << " " << localsassign.at(i).at(2) << "\n";
                localtogloblalscope.push_back(localsassign.at(i));
            }
        }
    }
    if(!localtogloblalscope.empty()){
        //cout << "ENTRE A LOCALTOGLOBALSCOPES" << "\n";
        bool variableonscope;
        int localtogloblalscopesize = localtogloblalscope.size()-1;
        for(int i=0;i<=localtogloblalscopesize;i++){
            variableonscope = false;
            for(int y=0;y<=globalsdeclsize;y++){
                if(localtogloblalscope.at(i).at(2)==globalsdecl.at(y).at(2)){
                    variableonscope=true;

                    /*cout << "LA VARIABLE LOCAL ESTA EN EL SCOPE GLOBAL\n";
                    cout << "SCOPE POSITION ON GLOBALSDECL: " << y <<"\n";
                    cout << "  Valor Decl: " << globalsdecl.at(y).at(0) << " " << globalsdecl.at(y).at(1) << " " << globalsdecl.at(y).at(2) << "\n";
                    cout << "  Valor: " << localtogloblalscope.at(i).at(0) << " " << localtogloblalscope.at(i).at(1) << " " << localtogloblalscope.at(i).at(2) << "\n";
                    break;
                }
            }
            if(variableonscope==false){
                string error = " ";
                //error = "Undeclared variable: " +" "+localtogloblalscope.at(i).at(2)+" "+"at column: "+localtogloblalscope.at(i).at(4)+"on line: "+localtogloblalscope.at(i).at(5);
                error = "Undeclared variable: "+ localtogloblalscope.at(i).at(2)+" at column: "+localtogloblalscope.at(i).at(4)+" on line: "+localtogloblalscope.at(i).at(5)+"\n";
                semanticerrors.push_back(error);
                /*cout << "LA VARIABLE LOCAL NO ESTA EN EL SCOPE GLOBAL\n";
                cout << "  Valor: " << localtogloblalscope.at(i).at(0) << " " << localtogloblalscope.at(i).at(1) << " " << localtogloblalscope.at(i).at(2) << "\n";
            }
        }
    }

}*/
void GetSeparateClasses(TablesStack &tb){
    int stackpositions = tb.GetStackSize()-1;
    vector<pElementSCH> bracestoclose;
    vector<pElementSCH> newclass;
    int sizebracestoclose;
    for(stackpositions;stackpositions>=0;stackpositions--){
          /*cout <<"------------------------------------\n";
          cout <<"TYPE: " << tb.at(stackpositions)->type << "\n";
          cout <<"TOKEN: " << tb.at(stackpositions)->tokenE << "\n";
          cout <<"VALUE1: " << tb.at(stackpositions)->value1->value << "\n";
          cout <<"VALUE2: " << tb.at(stackpositions)->value2->value << "\n";
          cout <<"------------------------------------\n";*/
          //sizebracestoclose = bra
          if(tb.at(stackpositions)->tokenE == "RBRACE" && tb.at(stackpositions)->value1->value == "1"){
                tb.at(stackpositions)->tokenE = "LBRACE";
                bracestoclose.push_back(tb.at(stackpositions));
                tb.at(stackpositions)->tokenE = "RBRACE";
                /*cout << "        ///////////////////////////////////\n";
                cout << "        DECISION TOMADA: AGREGAR UN SCOPE 1\n";
                cout << "        ///////////////////////////////////\n";*/
          }
          if(bracestoclose.empty() && tb.at(stackpositions)->type =="CLASS"){
                if(bracestoclose.empty() && tb.at(stackpositions)->type =="CLASS" && tb.at(stackpositions)->value1->value!="EXTENDS"){
                      newclass.push_back(tb.at(stackpositions));
                      listofclasses.push_back(newclass);
                      newclass.clear();
                      /*cout << "        ///////////////////////////////////\n";
                      cout << "        DECISION TOMADA: AGREGAR UNA CLASE A LA LISTA DE CLASES\n";
                      cout << "        ///////////////////////////////////\n";*/
                }
                //AGREGA LAS CLASES EXTENDS
                if(bracestoclose.empty() && tb.at(stackpositions)->type =="CLASS" && tb.at(stackpositions)->value1->value=="EXTENDS"){
                      newclass.push_back(tb.at(stackpositions));

                      /*cout << "        ///////////////////////////////////\n";
                      cout << "        DECISION TOMADA: AGREGAR UNA CLASE A LA LISTA DE CLASES\n";
                      cout << "        ///////////////////////////////////\n";*/
                }
                /*cout << "        ///////////////////////////////////\n";
                cout << "        DECISION TOMADA: AGREGAR UNA CLASE A LA LISTA DE CLASES\n";
                cout << "        ///////////////////////////////////\n";*/
          }
          if(!bracestoclose.empty() && tb.at(stackpositions)->tokenE !="LBRACE"|| (!bracestoclose.empty() && tb.at(stackpositions)->tokenE =="LBRACE" && tb.at(stackpositions)->value1->value != "1")){
                newclass.push_back(tb.at(stackpositions));
                /*cout << "        ///////////////////////////////////\n";
                cout << "        DECISION TOMADA:AGREGAR CUALQUIER COSA ADENTRO DE LA CLASE\n";
                cout << "        ///////////////////////////////////\n";*/

          }
          if(!bracestoclose.empty() && tb.at(stackpositions)->tokenE =="LBRACE" && tb.at(stackpositions)->value1->value == "1"){
                bracestoclose.pop_back();
                newclass.push_back(tb.at(stackpositions));
                /*cout << "        ///////////////////////////////////\n";
                cout << "        DECISION TOMADA:QUITAR EL SCOPE 1 PARA PASAR AL SIGUIENTE\n";
                cout << "        ///////////////////////////////////\n";
                cout << "        ///////////////////////////////////\n";
                cout <<"        TYPE: " << tb.at(stackpositions)->type << "\n";
                cout <<"        TOKEN: " << tb.at(stackpositions)->tokenE << "\n";
                cout <<"        VALUE1: " << tb.at(stackpositions)->value1->value << "\n";
                cout <<"        VALUE2: " << tb.at(stackpositions)->value2->value << "\n";
                cout << "        ///////////////////////////////////\n";*/

          }
    }
    //cout <<listofclasses.at(0).size() <<"--\n";
    /*for(int i=0;i<listofclasses.size();i++){
        int size = listofclasses.at(i).size();
        cout << "-----------------------------------\n";
        for(int y=0;y<size;y++){
            cout<< "Type: " <<listofclasses.at(i).at(y)->type<<"\n";
            cout<<"\tToken: " <<listofclasses.at(i).at(y)->tokenE<<"\n";
            cout<< "\tValue 1: " <<listofclasses.at(i).at(y)->value1->value<<"\n";
            cout<< "\tValue 2: " <<listofclasses.at(i).at(y)->value2->value<<"\n";
            cout<< "\tLine: " <<listofclasses.at(i).at(y)->rowE<<"\n";
            cout<< "\tColumn: " <<listofclasses.at(i).at(y)->columnE<<"\n";
        }
        cout << "-----------------------------------\n";
    }*/

    /*for(int y=0;y<globaldecl.size();y++){
        cout<< "Type: " <<globaldecl.at(y)->type << "\tToken: " <<globaldecl.at(y)->tokenE << "\tValue 1: " <<globaldecl.at(y)->value1->value<< "\tValue 2: " <<globaldecl.at(y)->value2->value<< "\tLine: " <<globaldecl.at(y)->rowE<< "\tColumn: " <<globaldecl.at(y)->columnE<<"\n";
    }*/


}
void CheckGlobalVariablesClass(vector<pElementSCH> aclass){
      int stackpositions = aclass.size();
      vector<pElementSCH> bracestoclose;
      vector<pElementSCH> classattributes;
      vector<pElementSCH> classmethods;
      for(int i=0;i<stackpositions;i++){
        cout <<"------------------------------------\n";
        cout <<"TYPE: " << aclass.at(i)->type << "\n";
        cout <<"TOKEN: " << aclass.at(i)->tokenE << "\n";
        cout <<"VALUE1: " << aclass.at(i)->value1->value << "\n";
        cout <<"VALUE2: " << aclass.at(i)->value2->value << "\n";
        cout <<"------------------------------------\n";
        if(aclass.at(i)->tokenE == "LBRACE" && aclass.at(i)->value1->value=="1"){
            cout << "        ///////////////////////////////////\n";
            cout << "        DECISION TOMADA: BREAK               \n";
            cout << "        ///////////////////////////////////\n";
            break;
        }
        if(aclass.at(i)->tokenE == "RBRACE" && aclass.at(i)->value1->value !="1"){
          cout << "        ///////////////////////////////////\n";
          cout << "        DECISION TOMADA: AGREGAR UN SCOPE PARA IGNORAR   \n";
          cout << "        ///////////////////////////////////\n";
            aclass.at(i)->tokenE = "LBRACE";
            bracestoclose.push_back(aclass.at(i));
            aclass.at(i)->tokenE = "RBRACE";
        }
        if(!bracestoclose.empty() && aclass.at(i)->tokenE =="LBRACE"){
          cout << "        ///////////////////////////////////\n";
          cout << "        DECISION TOMADA: QUITAR UN SCOPE PARA IGNORAR               \n";
          cout << "        BRACESTOCLOSESIZE:"<< bracestoclose.size()<<"\n";
          cout << "        ///////////////////////////////////\n";
            int sizebracestoclose = bracestoclose.size()-1;
            if(aclass.at(i)->value1->value==bracestoclose.at(sizebracestoclose)->value1->value){
                bracestoclose.pop_back();
            }
        }
        if(bracestoclose.empty() && aclass.at(i)->tokenE=="Variable"){

            /*if(aclass.at(i)->value1->value =="pPeso" || aclass.at(i)->value1->value =="pCarnet" ){
                aclass.at(i)->value2->value = "Func";
            }*/
            if(aclass.at(i)->value2->value!="Func" && aclass.at(i)->value2->value!="NewArray" && aclass.at(i)->value2->value!="NewClass"){
              cout << "        ///////////////////////////////////\n";
              cout << "        DECISION TOMADA: AGREGAR UNA VARIABLE               \n";
              cout << "        ///////////////////////////////////\n";

                classattributes.push_back(aclass.at(i));
            }
            //locals.push_back(tb.at(stackpositions));

            /*Descomentar para probar cuando tenga la estructura de declaraciones
            if(tb.at(stackpositions)->value2->value=="Func"){
                functionsdeclaration.push_back(tb.at(stackpositions));
            }
            if(tb.at(stackpositions)->value2->value=="NewArray"){
                arraysdeclaration.push_back(tb.at(stackpositions));
            }
            if(tb.at(stackpositions)->value2->value=="NewClass"){
                classesdeclaration.push_back(tb.at(stackpositions));
            }*/
        }
        /*if(bracestoclose.empty() && tb.at(stackpositions)->tokenE=="Variable"){
            globaldecl.push_back(tb.at(stackpositions));
        }*/
      }
      //cout << classattributes.size()<<"\n";
      classesattributes.push_back(classattributes);
      /*cout << "|||||||||||||||||||||||||||||||||||||||||||||\n";
      for(int i=0;i<classattributes.size();i++){

              cout<< "Type: " <<classattributes.at(i)->type<<"\n";
              cout<<"\tToken: " <<classattributes.at(i)->tokenE<<"\n";
              cout<< "\tValue 1: " <<classattributes.at(i)->value1->value<<"\n";
              cout<< "\tValue 2: " <<classattributes.at(i)->value2->value<<"\n";
              cout<< "\tLine: " <<classattributes.at(i)->rowE<<"\n";
              cout<< "\tColumn: " <<classattributes.at(i)->columnE<<"\n";
          cout << "|||||||||||||||||||||||||||||||||||||||||||||\n";
      }*/

}
void CheckVariables(vector<pElementSCH> aclass){
      CheckGlobalVariablesClass(aclass);
      /*for(int i=0;i<classesattributes.size();i++){
          int size = classesattributes.at(i).size();
          cout << "-----------------------------------\n";
          for(int y=0;y<size;y++){
              cout<< "Type: " <<classesattributes.at(i).at(y)->type<<"\n";
              cout<<"\tToken: " <<classesattributes.at(i).at(y)->tokenE<<"\n";
              cout<< "\tValue 1: " <<classesattributes.at(i).at(y)->value1->value<<"\n";
              cout<< "\tValue 2: " <<classesattributes.at(i).at(y)->value2->value<<"\n";
              cout<< "\tLine: " <<classesattributes.at(i).at(y)->rowE<<"\n";
              cout<< "\tColumn: " <<classesattributes.at(i).at(y)->columnE<<"\n";
          }
          cout << "-----------------------------------\n";
      }*/
      vector<pElementSCH> aclasstemp = aclass;
      int aclasssize = aclass.size()-1;
      int aclasstempsize = aclasstemp.size()-1;
      for(aclasstempsize;aclasstempsize>=0;aclasstempsize--){
        //cout << "STACKPOSITIONS: \n"<<stackpositions<<"\n";
          if(aclasstemp.at(aclasstempsize)->tokenE == "RBRACE"){
              aclass.pop_back();

              /*scopevalue =tbtemp.at(stackpositions)->value1->value;;
              tb.Pop();
              scopes = SearchLocalVariables(tb,scopevalue);
              scopes = DeleteOtherValues(scopes);
              scopes = DivideScopes(scopes);
              ChekingVariables(scopes);
              //Validar si hay declaraciones repetidas en un scope
              ChekingRepeatVariableDeclarations(scopes);
              //PrintSCSElements();*/
          }else{
              if(aclasstemp.at(aclasstempsize)->tokenE != "RBRACE" && !aclass.empty()){
                  aclass.pop_back();
              }

          }
    }
}
//Valida las variables en scopes globales y locales
vector<vector<pElementSCH > > ScopeCheckingVariablesClasses(TablesStack &tb){
    vector<vector<pElementSCH> > scopes;
    int listofclassestempsize;
    string scopevalue = " ";
    pElementSCH elements;
    //tb.printStack();
    //1.vector<vector<vector<string> > > scopes;
    GetSeparateClasses(tb);
    vector<pElementSCH> listofclassestemp;
    for(int i=0;i<listofclasses.size();i++){
        listofclassestemp = listofclasses.at(i);
        CheckVariables(listofclassestemp);

    }
    /*for(int i=0;i<listofclasses.size();i++){
        listofclasses.pop_back();
    }
    for(int i=0;i<listofclassestemp.size();i++){

            cout<< "Type: " <<listofclassestemp.at(i)->type<<"\n";
            cout<<"\tToken: " <<listofclassestemp.at(i)->tokenE<<"\n";
            cout<< "\tValue 1: " <<listofclassestemp.at(i)->value1->value<<"\n";
            cout<< "\tValue 2: " <<listofclassestemp.at(i)->value2->value<<"\n";
            cout<< "\tLine: " <<listofclassestemp.at(i)->rowE<<"\n";
            cout<< "\tColumn: " <<listofclassestemp.at(i)->columnE<<"\n";
        cout << "-----------------------------------\n";
    }*/


    /*for(int i=0;i<listofclasses.size();i++){
        listofclassessize = listofclasses.at(i).size();
        for(listofclassessize;listofclassessize>=0;listofclassessize--){
              //cout << "STACKPOSITIONS: \n"<<stackpositions<<"\n";
             if(list.at(stackpositions)->tokenE == "RBRACE"){
                  scopevalue =tbtemp.at(stackpositions)->value1->value;;
                  tb.Pop();
                  //scopes = SearchLocalVariablesClasses(tb);
                    //scopes = DeleteOtherValues(scopes);
                    //scopes = DivideScopes(scopes);
                    //ChekingVariables(scopes);
                    //Validar si hay declaraciones repetidas en un scope
                    //ChekingRepeatVariableDeclarations(scopes);
                    //PrintSCSElements();
            }else{
                  if(tbtemp.at(stackpositions)->tokenE != "RBRACE" && !tb.isEmpty()){
                      tb.Pop();
                  }

            }
    }*/
    /*for(stackpositions;stackpositions>=0;stackpositions--){
          //cout << "STACKPOSITIONS: \n"<<stackpositions<<"\n";
         if(tbtemp.at(stackpositions)->tokenE == "RBRACE"){
              scopevalue =tbtemp.at(stackpositions)->value1->value;;
              tb.Pop();
              //scopes = SearchLocalVariablesClasses(tb);
                //scopes = DeleteOtherValues(scopes);
                //scopes = DivideScopes(scopes);
                //ChekingVariables(scopes);
                //Validar si hay declaraciones repetidas en un scope
                //ChekingRepeatVariableDeclarations(scopes);
                //PrintSCSElements();
        }else{
              if(tbtemp.at(stackpositions)->tokenE != "RBRACE" && !tb.isEmpty()){
                  tb.Pop();
              }

        }
    }*/
    printSemanticErrors();
    elementsi.push_back(assignsvariables);
    return elementsi;
}


#endif // SCOPECHECKINGVARIABLESCLASSES_H_INCLUDED
