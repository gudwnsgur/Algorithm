var n = 0
var edges = 0
var cnt = 0
lateinit var graph: Array<Array<Boolean>>
lateinit var visited: BooleanArray

fun dfs(v: Int) {
    for(i in 1..n) {
        if(graph[v][i] && !visited[i]) {
            visited[i] = true
            dfs(i)
        }
    }
    return
}

fun main() = with(System.`in`.bufferedReader()) {
    var tk = readLine().trim().split(" ")
    n = tk[0].toInt()
    edges = tk[1].toInt()
    visited = BooleanArray(n+1)
    graph = Array(n+1) { Array(n+1) { false } }

    for(i in 1..edges) {
        tk = readLine().trim().split(" ")
        val (x, y) = tk[0].toInt() to tk[1].toInt()
        graph[x][y] = true
        graph[y][x] = true
    }

    for(i in 1..n) {
        if (!visited[i]) {
            cnt++
            visited[i] = true
            dfs(i)
        }
    }
    println(cnt)
}

