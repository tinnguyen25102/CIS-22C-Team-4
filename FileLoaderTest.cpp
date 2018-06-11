//
//  FileLoaderTest.cpp
//  
//
//  Created by Jasper Edbrooke on 6/10/18.
//

#include <stdio.h>
#include "FileLoader.cpp"
#include "Product.h"
#include <sstream>

class FileLoader;

int main(){
    
    string path = "products_in.txt";
    
    BST<Product> p(FileLoader::loadProducts(path));
    
    stringstream ss;
    
    p.printToFile(ss);
    
    cout << ss.str();
}
