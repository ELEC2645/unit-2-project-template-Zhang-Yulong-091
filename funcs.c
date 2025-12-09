#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcs.h"

#ifndef PI
#define PI 3.14159265358979323846
#endif

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_DATA 100

/* ---------- Local helpers (only used in this file) ---------- */

static void clear_input_buffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* discard extra characters */
    }
}

/* Read an integer with minimum value 'min' */
static int read_int_min(const char* prompt, int min)
{
    int value;
    int rc;

    for (;;) {
        printf_s("%s", prompt);
        rc = scanf_s("%d", &value);
        if (rc != 1) {
            printf_s("Invalid input. Please enter an integer.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();
        if (value < min) {
            printf_s("Value must be at least %d.\n", min);
            continue;
        }
        return value;
    }
}

/* Read an integer in [min, max] */
static int read_int_range(const char* prompt, int min, int max)
{
    int value;
    int rc;

    for (;;) {
        printf_s("%s", prompt);
        rc = scanf_s("%d", &value);
        if (rc != 1) {
            printf_s("Invalid input. Please enter an integer.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();
        if (value < min || value > max) {
            printf_s("Value must be between %d and %d.\n", min, max);
            continue;
        }
        return value;
    }
}

/* Read a double value */
static double read_double(const char* prompt)
{
    double value;
    int rc;

    for (;;) {
        printf_s("%s", prompt);
        rc = scanf_s("%lf", &value);
        if (rc != 1) {
            printf_s("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();
        return value;
    }
}

/* ====================== Linear Algebra Library ====================== */

static void matrix_addition(void)
{
    int rows, cols;
    int i, j;
    double A[MAX_ROWS][MAX_COLS];
    double B[MAX_ROWS][MAX_COLS];
    double C[MAX_ROWS][MAX_COLS];
    char prompt[64];

    rows = read_int_range("Enter number of rows (1-5): ", 1, MAX_ROWS);
    cols = read_int_range("Enter number of columns (1-5): ", 1, MAX_COLS);

    printf_s("\nEnter elements of matrix A:\n");
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            sprintf_s(prompt, sizeof(prompt), "A[%d][%d] = ", i + 1, j + 1);
            A[i][j] = read_double(prompt);
        }
    }

    printf_s("\nEnter elements of matrix B:\n");
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            sprintf_s(prompt, sizeof(prompt), "B[%d][%d] = ", i + 1, j + 1);
            B[i][j] = read_double(prompt);
        }
    }

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf_s("\nResult of A + B:\n");
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j)
            printf_s("%8.3f ", C[i][j]);
        printf_s("\n");
    }
}

static void matrix_subtraction(void)
{
    int rows, cols;
    int i, j;
    double A[MAX_ROWS][MAX_COLS];
    double B[MAX_ROWS][MAX_COLS];
    double C[MAX_ROWS][MAX_COLS];
    char prompt[64];

    rows = read_int_range("Enter number of rows (1-5): ", 1, MAX_ROWS);
    cols = read_int_range("Enter number of columns (1-5): ", 1, MAX_COLS);

    printf_s("\nEnter elements of matrix A:\n");
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            sprintf_s(prompt, sizeof(prompt), "A[%d][%d] = ", i + 1, j + 1);
            A[i][j] = read_double(prompt);
        }
    }

    printf_s("\nEnter elements of matrix B:\n");
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            sprintf_s(prompt, sizeof(prompt), "B[%d][%d] = ", i + 1, j + 1);
            B[i][j] = read_double(prompt);
        }
    }

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }

    printf_s("\nResult of A - B:\n");
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j)
            printf_s("%8.3f ", C[i][j]);
        printf_s("\n");
    }
}

static void matrix_multiplication(void)
{
    int r1, c1, c2;
    int i, j, k;
    double A[MAX_ROWS][MAX_COLS];
    double B[MAX_ROWS][MAX_COLS];
    double C[MAX_ROWS][MAX_COLS];
    char prompt[64];

    r1 = read_int_range("Enter number of rows of A (1-5): ", 1, MAX_ROWS);
    c1 = read_int_range("Enter number of columns of A (1-5): ", 1, MAX_COLS);

    printf_s("For multiplication, matrix B must have %d rows.\n", c1);
    c2 = read_int_range("Enter number of columns of B (1-5): ", 1, MAX_COLS);

    printf_s("\nEnter elements of matrix A:\n");
    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c1; ++j) {
            sprintf_s(prompt, sizeof(prompt), "A[%d][%d] = ", i + 1, j + 1);
            A[i][j] = read_double(prompt);
        }
    }

    printf_s("\nEnter elements of matrix B:\n");
    for (i = 0; i < c1; ++i) {      /* rows of B = columns of A = c1 */
        for (j = 0; j < c2; ++j) {
            sprintf_s(prompt, sizeof(prompt), "B[%d][%d] = ", i + 1, j + 1);
            B[i][j] = read_double(prompt);
        }
    }

    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j) {
            C[i][j] = 0.0;
            for (k = 0; k < c1; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf_s("\nResult of A * B:\n");
    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j)
            printf_s("%8.3f ", C[i][j]);
        printf_s("\n");
    }
}

/* determinant for n = 1..3 */
static void matrix_determinant(void)
{
    int n;
    int i, j;
    double M[3][3];
    double det;
    char prompt[64];

    n = read_int_range("Enter matrix size n (1-3, for n x n): ", 1, 3);

    printf_s("\nEnter elements of matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            sprintf_s(prompt, sizeof(prompt), "M[%d][%d] = ", i + 1, j + 1);
            M[i][j] = read_double(prompt);
        }
    }

    det = 0.0;
    if (n == 1) {
        det = M[0][0];
    }
    else if (n == 2) {
        det = M[0][0] * M[1][1] - M[0][1] * M[1][0];
    }
    else { /* n == 3 */
        double a = M[0][0], b = M[0][1], c = M[0][2];
        double d = M[1][0], e = M[1][1], f = M[1][2];
        double g = M[2][0], h = M[2][1], i2 = M[2][2];

        det = a * (e * i2 - f * h)
            - b * (d * i2 - f * g)
            + c * (d * h - e * g);
    }

    printf_s("\nDeterminant = %.6f\n", det);
}

void menu_linear_algebra(void)
{
    int choice;

    for (;;) {
        printf_s("\n===== Linear Algebra Library =====\n");
        printf_s("1. Matrix addition\n");
        printf_s("2. Matrix subtraction\n");
        printf_s("3. Matrix multiplication\n");
        printf_s("4. Determinant (up to 3x3)\n");
        printf_s("5. Exit to main menu\n");
        printf_s("==================================\n");

        choice = read_int_range("Select item: ", 1, 5);

        switch (choice) {
        case 1:
            matrix_addition();
            break;
        case 2:
            matrix_subtraction();
            break;
        case 3:
            matrix_multiplication();
            break;
        case 4:
            matrix_determinant();
            break;
        case 5:
        default:
            return; /* back to main menu */
        }
    }
}

/* ====================== Basic Statistical Tools ====================== */

static double compute_mean(const double* data, int n)
{
    int i;
    double sum = 0.0;
    for (i = 0; i < n; ++i)
        sum += data[i];
    return sum / n;
}

/* Simple bubble sort */
static void sort_array(double* a, int n)
{
    int i, j;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j + 1]) {
                double tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

static double compute_median(const double* data, int n)
{
    double tmp[MAX_DATA];
    int i;
    double result;

    for (i = 0; i < n; ++i)
        tmp[i] = data[i];

    sort_array(tmp, n);

    if (n % 2 == 1) {
        result = tmp[n / 2];
    }
    else {
        result = (tmp[n / 2 - 1] + tmp[n / 2]) / 2.0;
    }
    return result;
}

static double compute_variance(const double* data, int n)
{
    int i;
    double mean = compute_mean(data, n);
    double sum_sq = 0.0;

    for (i = 0; i < n; ++i) {
        double diff = data[i] - mean;
        sum_sq += diff * diff;
    }
    /* population variance */
    return sum_sq / n;
}

static double compute_stddev(const double* data, int n)
{
    double var = compute_variance(data, n);
    return sqrt(var);
}

void menu_statistics(void)
{
    int n;
    int choice;
    int i;
    double data[MAX_DATA];
    char prompt[64];

    n = read_int_range("Enter number of data points (1-100): ", 1, MAX_DATA);

    printf_s("\nEnter %d data values:\n", n);
    for (i = 0; i < n; ++i) {
        sprintf_s(prompt, sizeof(prompt), "x[%d] = ", i + 1);
        data[i] = read_double(prompt);
    }

    for (;;) {
        printf_s("\n===== Basic Statistical Tools =====\n");
        printf_s("1. Mean\n");
        printf_s("2. Median\n");
        printf_s("3. Variance (population)\n");
        printf_s("4. Standard deviation (population)\n");
        printf_s("5. Exit to main menu\n");
        printf_s("===================================\n");

        choice = read_int_range("Select item: ", 1, 5);

        switch (choice) {
        case 1: {
            double mean = compute_mean(data, n);
            printf_s("Mean = %.6f\n", mean);
            break;
        }
        case 2: {
            double median = compute_median(data, n);
            printf_s("Median = %.6f\n", median);
            break;
        }
        case 3: {
            double var = compute_variance(data, n);
            printf_s("Variance = %.6f\n", var);
            break;
        }
        case 4: {
            double sd = compute_stddev(data, n);
            printf_s("Standard deviation = %.6f\n", sd);
            break;
        }
        case 5:
        default:
            return;
        }
    }
}

/* ====================== Simple Electrical Circuit ====================== */

static void compute_resistance(void)
{
    double voltage = read_double("Enter voltage (V): ");
    double current = read_double("Enter current (A): ");

    if (current == 0.0) {
        printf_s("Current cannot be zero when computing resistance.\n");
        return;
    }

    printf_s("Resistance R = V / I = %.6f ohms\n", voltage / current);
}

static void compute_voltage(void)
{
    double current = read_double("Enter current (A): ");
    double resistance = read_double("Enter resistance (ohms): ");
    double voltage = current * resistance;
    printf_s("Voltage V = I * R = %.6f volts\n", voltage);
}

static void compute_current(void)
{
    double voltage = read_double("Enter voltage (V): ");
    double resistance = read_double("Enter resistance (ohms): ");

    if (resistance == 0.0) {
        printf_s("Resistance cannot be zero when computing current.\n");
        return;
    }

    printf_s("Current I = V / R = %.6f amperes\n", voltage / resistance);
}

static void compute_total_resistance(void)
{
    int n;
    int i;
    double* R;
    double sum;
    double inv_sum;
    int type;

    n = read_int_min("Enter number of resistors (>=1): ", 1);
    R = (double*)malloc((size_t)n * sizeof(double));
    if (!R) {
        printf_s("Memory allocation failed.\n");
        return;
    }

    for (i = 0; i < n; ++i) {
        char prompt[64];
        sprintf_s(prompt, sizeof(prompt), "R[%d] (ohms) = ", i + 1);
        R[i] = read_double(prompt);
    }

    printf_s("\n1. Series connection\n");
    printf_s("2. Parallel connection\n");
    type = read_int_range("Select type: ", 1, 2);

    if (type == 1) {
        sum = 0.0;
        for (i = 0; i < n; ++i)
            sum += R[i];
        printf_s("Total series resistance = %.6f ohms\n", sum);
    }
    else {
        inv_sum = 0.0;
        for (i = 0; i < n; ++i) {
            if (R[i] == 0.0) {
                printf_s("Resistance value cannot be zero in a parallel network.\n");
                free(R);
                return;
            }
            inv_sum += 1.0 / R[i];
        }
        if (inv_sum == 0.0) {
            printf_s("Sum of reciprocals is zero. Cannot compute.\n");
        }
        else {
            printf_s("Total parallel resistance = %.6f ohms\n", 1.0 / inv_sum);
        }
    }

    free(R);
}

void menu_circuit(void)
{
    int choice;

    for (;;) {
        printf_s("\n===== Simple Electrical Circuit =====\n");
        printf_s("1. Compute resistance (R = V / I)\n");
        printf_s("2. Compute voltage (V = I * R)\n");
        printf_s("3. Compute current (I = V / R)\n");
        printf_s("4. Compute total resistance\n");
        printf_s("5. Exit to main menu\n");
        printf_s("=====================================\n");

        choice = read_int_range("Select item: ", 1, 5);

        switch (choice) {
        case 1:
            compute_resistance();
            break;
        case 2:
            compute_voltage();
            break;
        case 3:
            compute_current();
            break;
        case 4:
            compute_total_resistance();
            break;
        case 5:
        default:
            return;
        }
    }
}

/* ====================== Simple Calculator ====================== */

static void simple_arithmetic_calculator(void)
{
    char line[128];

    printf_s("\nEnter expressions in the form: a op b\n");
    printf_s("Supported operators: +  -  *  /\n");
    printf_s("Type 'q' to return to the previous menu.\n\n");

    for (;;) {
        double a, b, result;
        char op;
        int valid;

        printf_s("Expression: ");
        if (!fgets(line, sizeof(line), stdin)) {
            printf_s("Input error.\n");
            return;
        }

        if (line[0] == 'q' || line[0] == 'Q') {
            return;
        }

        if (sscanf_s(line, "%lf %c %lf", &a, &op, 1, &b) != 3) {
            printf_s("Invalid format. Example: 3.5 * 2\n");
            continue;
        }

        valid = 1;
        switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0.0) {
                printf_s("Error: division by zero.\n");
                valid = 0;
            }
            else {
                result = a / b;
            }
            break;
        default:
            printf_s("Unsupported operator '%c'. Use + - * /.\n", op);
            valid = 0;
        }

        if (valid) {
            printf_s("Result = %.10g\n", result);
        }
    }
}

static void geometry_circle(void)
{
    double r = read_double("Enter radius: ");
    double area, peri;

    if (r < 0) {
        printf_s("Radius cannot be negative.\n");
        return;
    }
    area = PI * r * r;
    peri = 2 * PI * r;
    printf_s("Circle area = %.6f\n", area);
    printf_s("Circle circumference = %.6f\n", peri);
}

static void geometry_square(void)
{
    double a = read_double("Enter side length: ");
    double area, peri;

    if (a < 0) {
        printf_s("Side length cannot be negative.\n");
        return;
    }
    area = a * a;
    peri = 4 * a;
    printf_s("Square area = %.6f\n", area);
    printf_s("Square perimeter = %.6f\n", peri);
}

static void geometry_rectangle(void)
{
    double w = read_double("Enter width: ");
    double h = read_double("Enter height: ");
    double area, peri;

    if (w < 0 || h < 0) {
        printf_s("Width and height cannot be negative.\n");
        return;
    }
    area = w * h;
    peri = 2 * (w + h);
    printf_s("Rectangle area = %.6f\n", area);
    printf_s("Rectangle perimeter = %.6f\n", peri);
}

static void geometry_sector(void)
{
    double r = read_double("Enter radius: ");
    double angle = read_double("Enter central angle (degrees): ");
    double area, arc, peri;

    if (r < 0) {
        printf_s("Radius cannot be negative.\n");
        return;
    }
    if (angle < 0) {
        printf_s("Angle cannot be negative.\n");
        return;
    }

    area = PI * r * r * (angle / 360.0);
    arc = 2 * PI * r * (angle / 360.0);
    peri = 2 * r + arc;

    printf_s("Sector area = %.6f\n", area);
    printf_s("Sector arc length = %.6f\n", arc);
    printf_s("Sector perimeter = %.6f\n", peri);
}

static void geometry_calculator(void)
{
    int choice;

    for (;;) {
        printf_s("\n===== Geometry Calculator =====\n");
        printf_s("1. Circle (area & circumference)\n");
        printf_s("2. Square (area & perimeter)\n");
        printf_s("3. Rectangle (area & perimeter)\n");
        printf_s("4. Sector (area, arc length & perimeter)\n");
        printf_s("5. Exit to previous menu\n");
        printf_s("================================\n");

        choice = read_int_range("Select item: ", 1, 5);

        switch (choice) {
        case 1:
            geometry_circle();
            break;
        case 2:
            geometry_square();
            break;
        case 3:
            geometry_rectangle();
            break;
        case 4:
            geometry_sector();
            break;
        case 5:
        default:
            return;
        }
    }
}

void menu_calculator(void)
{
    int choice;

    for (;;) {
        printf_s("\n===== Simple Calculator =====\n");
        printf_s("1. Simple arithmetic calculator\n");
        printf_s("2. Geometry information calculator\n");
        printf_s("3. Exit to main menu\n");
        printf_s("================================\n");

        choice = read_int_range("Select item: ", 1, 3);

        switch (choice) {
        case 1:
            simple_arithmetic_calculator();
            break;
        case 2:
            geometry_calculator();
            break;
        case 3:
        default:
            return;
        }
    }
}

/* ====================== Query Assistant ====================== */

void menu_query_assistant(void)
{
    int choice;
    char answer;

    for (;;) {
        printf_s("\n===== Query Assistant =====\n");
        printf_s("1. Matrix operations\n");
        printf_s("2. Statistical data tools\n");
        printf_s("3. Voltage, current and resistance\n");
        printf_s("4. Arithmetic and geometry calculations\n");
        printf_s("5. Exit to main menu\n");
        printf_s("===========================\n");

        choice = read_int_range("Select item: ", 1, 5);

        if (choice == 5) {
            return;
        }

        switch (choice) {
        case 1:
            printf_s("\nMatrix operations module includes:\n");
            printf_s(" - Matrix addition\n");
            printf_s(" - Matrix subtraction\n");
            printf_s(" - Matrix multiplication\n");
            printf_s(" - Determinant (up to 3x3)\n");
            printf_s("Open this module now? (y/n): ");
            scanf_s(" %c", &answer, 1);
            clear_input_buffer();
            if (answer == 'y' || answer == 'Y') {
                menu_linear_algebra();
            }
            break;
        case 2:
            printf_s("\nBasic statistical tools module includes:\n");
            printf_s(" - Mean\n");
            printf_s(" - Median\n");
            printf_s(" - Variance\n");
            printf_s(" - Standard deviation\n");
            printf_s("Open this module now? (y/n): ");
            scanf_s(" %c", &answer, 1);
            clear_input_buffer();
            if (answer == 'y' || answer == 'Y') {
                menu_statistics();
            }
            break;
        case 3:
            printf_s("\nSimple electrical circuit module includes:\n");
            printf_s(" - Compute resistance\n");
            printf_s(" - Compute voltage\n");
            printf_s(" - Compute current\n");
            printf_s(" - Compute total resistance (series/parallel)\n");
            printf_s("Open this module now? (y/n): ");
            scanf_s(" %c", &answer, 1);
            clear_input_buffer();
            if (answer == 'y' || answer == 'Y') {
                menu_circuit();
            }
            break;
        case 4:
            printf_s("\nSimple calculator module includes:\n");
            printf_s(" - Arithmetic calculator (a op b)\n");
            printf_s(" - Geometry calculator (area & perimeter)\n");
            printf_s("Open this module now? (y/n): ");
            scanf_s(" %c", &answer, 1);
            clear_input_buffer();
            if (answer == 'y' || answer == 'Y') {
                menu_calculator();
            }
            break;
        default:
            /* should not reach here because of range check */
            break;
        }
    }
}