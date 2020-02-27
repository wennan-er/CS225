#include "abstractsyntaxtree.h"

/**
 * Calculates the value from an AST (Abstract Syntax Tree). To parse numbers from strings, please use std::stod
 * @return A double representing the calculated value from the expression transformed into an AST
 */
 double AbstractSyntaxTree::add(double para1, double para2) const{
    return para1+para2;
 }
 double AbstractSyntaxTree::subtract(double para1, double para2) const{
    return para1-para2;
 }
 double AbstractSyntaxTree::multiply(double para1, double para2) const{
    return para1*para2;
 }
 double AbstractSyntaxTree::devide(double para1, double para2) const{
    return para1/para2;
 }
double AbstractSyntaxTree::eval() const {
    // @TODO Your code goes here...
    return eval(root);
}

double AbstractSyntaxTree::eval(AbstractSyntaxTree::Node* subnode) const {
    if (subnode!=NULL){
      if (((subnode->left)==NULL) && ((subnode->right)==NULL)){
        return std::stod(subnode->elem);
      }else{
        if (subnode->elem == "+"){
          return add(eval(subnode->left),eval(subnode->right));
        }
        if (subnode->elem == "-"){
          return subtract(eval(subnode->left),eval(subnode->right));
        }
        if (subnode->elem== "*"){
          return multiply(eval(subnode->left),eval(subnode->right));
        }
        if (subnode->elem == "/"){
          return devide(eval(subnode->left),eval(subnode->right));
        }
      }
    }
    return 0;

}
