// In Camera.h
class Camera
{
public:
    void ZoomIn();
    void ZoomOut();
private:
    float m_zoomLevel;
    float m_zoomSpeed;
    const float m_minZoomLevel = 60.0f;
    const float m_maxZoomLevel = 500.0f;
};

// In Camera.cpp
void Camera::ZoomIn()
{
    m_zoomLevel += m_zoomSpeed;
    if (m_zoomLevel > m_maxZoomLevel) {
        m_zoomLevel = m_maxZoomLevel;
    }
}

void Camera::ZoomOut()
{
    m_zoomLevel -= m_zoomSpeed;
    if (m_zoomLevel < m_minZoomLevel) {
        m_zoomLevel = m_minZoomLevel;
    }
}