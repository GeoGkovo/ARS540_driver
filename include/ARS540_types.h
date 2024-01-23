#include <cstdint>

namespace ARS540
{
    enum RadarMethodID : std::uint16_t
    {
        OBJECTLIST = 329,
        SENSORCONFIGURATION = 390,
        STATUS = 380,
        ACCELERATIONLATERALCOG = 321,
        ACCELERATIONLONGITUDINALCOG = 322,
        CHARACTERISTICSPEED = 328,
        DRIVINGDIRECTION = 325,
        STEERINGANGLEFRONTAXLE = 327,
        VELOCITYVEHICLE = 323,
        YAWRATE = 326
    };

    struct alignas(1) ObjectListMessage
    {
        std::uint64_t CRC;
        std::uint32_t length;
        std::uint32_t SQC;
        std::uint32_t dataID;
        std::uint32_t timestamp_ns;
        std::uint32_t timestamp_s;
        std::uint8_t timestamp_sync_status;
        std::uint32_t event_data_qualifier;
        std::uint8_t extended_qualifier;
        std::uint8_t object_list_object_num;
        std::uint8_t radar_objects[9350]; // Migrate the magic number
    };

    struct alignas(1) RadarStatusMessage
    {
        float Longitudinal;
        float Lateral;
        float Vertical;
        float Yaw;
        float Pitch;
        std::uint8_t PlugOrientation;
        float Length;
        float Width;
        float Height;
        float Wheelbase;
        std::uint16_t MaximumDistance;
        std::uint8_t FrequencySlot;
        std::uint8_t CycleTime;
        std::uint8_t TimeSlot;
        std::uint8_t HCC;
        std::uint8_t Powersave_Standstill;
        std::uint32_t SensorIPAddress_0;
        std::uint32_t SensorIPAddress_1;
        std::uint8_t Configuration_counter;
        std::uint8_t Status_LongitudinalVelocity;
        std::uint8_t Status_LongitudinalAcceleration;
        std::uint8_t Status_LateralAcceleration;
        std::uint8_t Status_YawRate;
        std::uint8_t Status_SteeringAngle;
        std::uint8_t Status_DrivingDirection;
        std::uint8_t Status_CharacteristicSpeed;
        std::uint8_t Status_Radar;
    };

    struct alignas(1) RadarObject
    {
        std::uint16_t u_StatusSensor;
        std::uint32_t u_ID;
        std::uint16_t u_Age;
        std::uint8_t u_StatusMeasurement;
        std::uint8_t u_StatusMovement;
        std::uint16_t u_Position_InvalidFlags;
        std::uint8_t u_Position_Reference;
        float u_Position_X;
        float u_Position_X_STD;
        float u_Position_Y;
        float u_Position_Y_STD;
        float u_Position_Z;
        float u_Position_Z_STD;
        float u_Position_CovarianceXY;
        float u_Position_Orientation;
        float u_Position_Orientation_STD;
        std::uint8_t u_Existence_InvalidFlags;
        float u_Existence_Probability;
        float u_Existence_PPV;
        std::uint8_t u_Classification_Car;
        std::uint8_t u_Classification_Truck;
        std::uint8_t u_Classification_Motorcycle;
        std::uint8_t u_Classification_Bicycle;
        std::uint8_t u_Classification_Pedestrian;
        std::uint8_t u_Classification_Animal;
        std::uint8_t u_Classification_Hazard;
        std::uint8_t u_Classification_Unknown;
        std::uint8_t u_Classification_Overdrivable;
        std::uint8_t u_Classification_Underdrivable;
        std::uint8_t u_Dynamics_AbsVel_InvalidFlags;
        float f_Dynamics_AbsVel_X;
        float f_Dynamics_AbsVel_X_STD;
        float f_Dynamics_AbsVel_Y;
        float f_Dynamics_AbsVel_Y_STD;
        float f_Dynamics_AbsVel_CovarianceXY;
        std::uint8_t u_Dynamics_RelVel_InvalidFlags;
        float f_Dynamics_RelVel_X;
        float f_Dynamics_RelVel_X_STD;
        float f_Dynamics_RelVel_Y;
        float f_Dynamics_RelVel_Y_STD;
        float f_Dynamics_RelVel_CovarianceXY;
        std::uint8_t u_Dynamics_AbsAccel_InvalidFlags;
        float f_Dynamics_AbsAccel_X;
        float f_Dynamics_AbsAccel_X_STD;
        float f_Dynamics_AbsAccel_Y;
        float f_Dynamics_AbsAccel_Y_STD;
        float f_Dynamics_AbsAccel_CovarianceXY;
        std::uint8_t u_Dynamics_RelAccel_InvalidFlags;
        float f_Dynamics_RelAccel_X;
        float f_Dynamics_RelAccel_X_STD;
        float f_Dynamics_RelAccel_Y;
        float f_Dynamics_RelAccel_Y_STD;
        float f_Dynamics_RelAccel_CovarianceXY;
        std::uint8_t u_Dynamics_Orientation_InvalidFlags;
        float u_Dynamics_Orientation_Rate_Mean;
        float u_Dynamics_Orientation_Rate_STD;
        std::uint32_t u_Shape_Length_Status;
        std::uint8_t u_Shape_Length_Edge_InvalidFlags;
        float u_Shape_Length_Edge_Mean;
        float u_Shape_Length_Edge_STD;
        std::uint32_t u_Shape_Width_Status;
        std::uint8_t u_Shape_Width_Edge_InvalidFlags;
        float u_Shape_Width_Edge_Mean;
        float u_Shape_Width_Edge_STD;
    };

    struct alignas(1) SensorConfigMessage
    {
        std::uint16_t CRC;
        std::uint16_t Length;
        std::int8_t SQC;
        std::int8_t SensorConfig_SensorID;
        std::int16_t SensorConfig_LongPos;
        std::int16_t SensorConfig_LatPos;
        std::int16_t SensorConfig_VertPos;
        std::int16_t SensorConfig_LongPosCoG;
        std::int16_t SensorConfig_YawAngle;
        std::int8_t SensorConfig_Orientation;
        std::int16_t SensorConfig_Damping;
        std::int8_t SensorConfig_StoreInNvm;
        std::int8_t SensorConfig_NewEthParam;
        std::uint32_t SensorConfig_NewSensorIP;
        std::uint16_t SensorConfig_NewPortRx;
        std::uint16_t SensorConfig_NewPortTx;
        std::int8_t SensorConfig_NewSensorVLAN;
        std::int8_t SensorConfig_NewSensorMAC0;
        std::int8_t SensorConfig_NewSensorMAC1;
        std::int8_t SensorConfig_NewSensorMAC2;
        std::int8_t SensorConfig_NewSensorMAC3;
        std::int8_t SensorConfig_NewSensorMAC4;
        std::int8_t SensorConfig_NewSensorMAC5;
        std::int16_t SensorConfig_Message;
    };

    struct alignas(1) HeaderFirstPart
    {
        std::uint16_t ServiceID;
        std::uint16_t MethodID;
        std::uint32_t Length;
    };
};