{
//     if (n >= k)
//     {
//         if (n == k)
//         {
//             return 1;
//         }
//         else if (k == 0)
//         {
//             return 1;
//         }
//         else if (k == 1)
//         {
//             return 1;
//         }
//         else if (o[n][k] != -1)
//         {
//             return o[n][k];
//         }
//         else
//         {
//             o[n][k] = f(n - 1, k) + f(n - 1, k - 2);
//             return o[n][k];
//             // return f(n - 1, k) + f(n - 1, k - 2);
//         }
//     }
//     return 0;
// }