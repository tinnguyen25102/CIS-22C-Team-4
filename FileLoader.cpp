//
//  FileLoader.cpp
//  
//
//  Created by Jasper Edbrooke on 6/10/18.
//

#include "FileLoader.h"


BST<Product> FileLoader::loadProducts(string path){

	cout << "loading products" << endl;

    BST<Product> products;
    ifstream fis(path.c_str());
    string line;
    if (fis.is_open()) {
        while (getline(fis,line)) {
            string manf_company = line;
            string model;
            getline(fis,model);
            double screen_size;
            fis >> screen_size;
            getline(fis,line); //advance to the next line
            unsigned cpuGen;
            fis >> cpuGen;
            getline(fis,line); //advance to the next line
            unsigned year;
            fis >> year;
            getline(fis,line); //advance to the next line
            unsigned price;
            fis >> price;
            getline(fis,line); //advance to the next line
            
            Product p(manf_company,model,screen_size,cpuGen,year,price);
            products.insert(p);
            
            getline(fis,line); //skip the emtpy line
            
        }
    }
    fis.close();
    return products;
}
