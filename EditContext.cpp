#include "EditContext.h"
EditContext *EditContext::instance = nullptr;
EditContext(){}
EditContext *EditContext::getInstance(){
    if(!EditContext::instance){
        EditContext::instance = new EditContext;
    }
    return EditContext::instance;
}