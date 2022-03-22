import java.io.*

val br = BufferedReader(InputStreamReader(System.`in`))
fun main() {
    val sum = br.readLine().toList().sumOf { ch ->
        if (ch in 'a'..'z') ch - 'a' + 1
        else ch - 'A' + 27
    }
   println(
       if (sum == 1 || sum.toBigInteger().isProbablePrime(10)) "It is a prime word."
       else "It is not a prime word."
   )
}


