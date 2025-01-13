// SemaphoreGuard.h
#ifndef SEMAPHORE_GUARD_H
#define SEMAPHORE_GUARD_H

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

class SemaphoreGuard {
public:
    // Costruttore che acquisisce il semaforo (mutex)
    explicit SemaphoreGuard(SemaphoreHandle_t mutex);

    // Distruttore che rilascia il semaforo (mutex)
    ~SemaphoreGuard();

    // Disabilitare il copia costruttore e l'operatore di assegnazione
    SemaphoreGuard(const SemaphoreGuard&) = delete;
    SemaphoreGuard& operator=(const SemaphoreGuard&) = delete;

private:
    SemaphoreHandle_t m_mutex;
};

#endif // SEMAPHORE_GUARD_H
