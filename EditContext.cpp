#include "EditContext.h"
EditContext *EditContext::instance = nullptr;
EditContext::EditContext(){
    student = nullptr;
}
EditContext *EditContext::getInstance(){
    if(!EditContext::instance){
        EditContext::instance = new EditContext;
    }
    return EditContext::instance;
}