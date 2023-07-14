#define STACK_MAX 256

typedef enum{
    OBJ_INT,
    OBJ_PAIR,

}ObjectType;

typedef struct sObject {
  ObjectType type;

  union {
    
    int value;

 
    struct {
      struct sObject* head;
      struct sObject* tail;
    };
  };
} Object;


typedef struct{
    Object* stack[STACK_MAX];
    int stackSize;
}VM;

VM* newVM(){
    VM* vm = malloc(sizeof(VM));
    vm->stackSize=0 ;
    return vm;
}

void push(VM* vm, Object* value){
    assert(vm->stackSize<STACK_MAX,"Stack overflow!");
    vm->stack[vm->stackSize++]=value;

}

Object*pop(VM*vm){
    assert(vm->stackSize>0,"Stack underflow!");
    return vm->stack[--vm->stackSize];

}

Object* newObject(VM* vm, ObjectType type) {
  Object* object = malloc(sizeof(Object));
  object-> type = type;
  return object;
}

void pushInt(VM* vm, int intValue) {
  Object* object = newObject(vm, OBJ_INT);
  object->value = intValue;
  push(vm, object);
}

Object* pushPair(VM* vm) {
  Object* object = newObject(vm, OBJ_PAIR);
  object->tail = pop(vm);
  object->head = pop(vm);

  push(vm, object);
  return object;
}

// marca marky
//
//
typedef struct sObject{
  unsigned char marked;

} Object;


void markAll(VM* vm){
for (int i = 0; i < vm-> stackSize; i++){
    mark(vm->stack [i]);
  }

}

void markAll (Object* object){
 object->marked = 1;
}


void mark(Object* object ){
    object->marked = 1; 
}

void mark (Object* object){
    object->marked = 1;
    if (object->type == OBJ_PAIR){
        mark(object->head);
        mark(object->tail);
    }
}