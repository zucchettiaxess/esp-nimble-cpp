#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "SemaphoreGuard.h"

// #include "NimBLELog.h"
// #include "definitions.h"


SemaphoreGuard::SemaphoreGuard(SemaphoreHandle_t mutex) : m_mutex(mutex) {
    // Acquisisce il semaforo (mutex)
    if (m_mutex != nullptr) 
    {
        xSemaphoreTake(m_mutex, portMAX_DELAY);
        // const char* taskName = pcTaskGetName(xTaskGetCurrentTaskHandle());
        
        // if(ris == pdTRUE)
        // {
        //     BLE_LIB_DEBUGOUT("CS %s\n", taskName);
        // }
        // else
        // {
        //     BLE_LIB_DEBUGOUT("___ Warning: Task (%s) Semaphore NOT Take ____\n", taskName);
        // }
    }
}

SemaphoreGuard::~SemaphoreGuard() {
    // Rilascia il semaforo (mutex) automaticamente quando l'oggetto viene distrutto
    if (m_mutex != nullptr) 
    {
        xSemaphoreGive(m_mutex);
        // const char* taskName = pcTaskGetName(xTaskGetCurrentTaskHandle());

        // if(ris == pdTRUE)
        // {
        //   BLE_LIB_DEBUGOUT("DS %s\n", taskName); 
        // }
        // else
        // {
        //   BLE_LIB_DEBUGOUT("___ Warning: Task (%s) Semaphore NOT Released ____\n", taskName);
        // }
    }
}
