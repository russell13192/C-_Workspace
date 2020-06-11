/*
 * Author: George Murray
 * Date: 05/26/2019
 */

#include <cmath>
#include <iostream>

void distance_from_waypoint(float lat1, float long1, float lat2, float long2)
{
    // WGS 84
    float a = 6378137.0;
    float f = 1 / 298.257223563;
    float b = 6356752.314245l;
    float current_pos[] = {lat1, long1};
    float waypoint_pos[] = {lat2, long2};
    // Tan U1
    const float tan_u1 = (1 - f) * std::tan(lat1);
    const float tan_u2 = (1 - f) * std::tan(lat2);
    // Longitudinal distance
    const float cos_u1 = 1 / std::sqrt(1 + tan_u1 * tan_u1);
    const float cos_u2 = 1 / std::sqrt(1 + tan_u2 * tan_u2);
    const float sin_u1 = tan_u1 * cos_u1;
    const float sin_u2 = tan_u2 * cos_u2;
    // Iterate until complete
    const double L = long2 - long1;
    float lambda = L;
    float diff, sigma;
    float cos_alpha_sq, cos_2sigma_m;
    float cos_sigma, sin_sigma;

    while (true)
    {
        float sin_lambda = std::sin(lambda);
        float cos_lambda = std::cos(lambda);

        float c1 = (cos_u2 * sin_lambda) * (cos_u2 * sin_lambda);
        float c2 = (cos_u1 * sin_u2);
        float c3 = (sin_u1 * cos_u2 * cos_lambda);

        // Sin sigma
        sin_sigma = std::sqrt(c1 + (c2 - c3) * (c2 - c3));
        // Cos sigma
        cos_sigma = sin_u1 * sin_u2 + cos_u1 * cos_u2 * cos_lambda;
        // Sigma
        sigma = std::atan2(sin_sigma, cos_sigma);
        // sin alpha
        float sin_alpha = (cos_u1 * cos_u2 * sin_lambda) / (sin_sigma);

        // cos^2 alpha
        cos_alpha_sq = 1 - (sin_alpha * sin_alpha);

        // cos^2 2sigmam
        cos_2sigma_m = cos_sigma - (2 * sin_u1 * sin_u2) / (cos_alpha_sq);

        // C
        float C = (f / 16.0) * cos_alpha_sq * (4 + f * (4 - 3 * cos_alpha_sq));

        // Update Lambda
        diff = lambda;
        lambda = L + (1 - C) * f * sin_alpha * (sigma + C * sin_sigma * (cos_2sigma_m + C * cos_sigma * (-1 + 2 * cos_2sigma_m * cos_2sigma_m)));
        diff = lambda - diff;
        if (std::fabs(diff) < 0.00001)
        {
            break;
        }
    }

    // U2
    float u_sq = cos_alpha_sq * (a * a - b * b) / (b * b);

    // Compute A, B
    float A = 1 + (u_sq / 16384) * (4096 + u_sq * (-768 + u_sq * (320 - 175 * u_sq)));

    float B = (u_sq / 1024) * (256 + u_sq * (-128 + u_sq * (-128 + u_sq * (74 - 47 * u_sq))));

    // Sigma
    float cos_2sigma_m_sq = cos_2sigma_m * cos_2sigma_m;
    float delta_sigma = B * sin_sigma * (cos_2sigma_m + (B / 4.0) * (cos_sigma * (-1 * 2 * cos_2sigma_m_sq) - (B / 6.0) * cos_2sigma_m * (-3 + 4 * sin_sigma * sin_sigma) * (-3 + 4 * cos_2sigma_m_sq)));

    // Distance
    float s = b * A * (sigma - delta_sigma);
    std::cout << "Distance between points: " << s << std::endl;
}

int main(int argc, char const *argv[])
{
    const float latitude_01  =   39.5 * M_PI / 180.0;
    const float longitude_01 = -120.5 * M_PI / 180.0;

    const float latitude_02 =    40 * M_PI / 180.0;
    const float longitude_02 = -119 * M_PI / 180.0;

    // Set the datum components
    const float a = 6378137.0;
    const float b = 6356752.314245;
    distance_from_waypoint(latitude_01, longitude_01, latitude_02, longitude_02);
    return 0;
}

