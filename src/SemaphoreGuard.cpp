#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "SemaphoreGuard.h"

SemaphoreGuard::SemaphoreGuard(SemaphoreHandle_t mutex) : m_mutex(mutex) {
    // Acquisisce il semaforo (mutex)
    if (m_mutex != nullptr) {
        xSemaphoreTake(m_mutex, portMAX_DELAY);
    }
}

SemaphoreGuard::~SemaphoreGuard() {
    // Rilascia il semaforo (mutex) automaticamente quando l'oggetto viene distrutto
    if (m_mutex != nullptr) {
        xSemaphoreGive(m_mutex);
    }
}
