<h1>Convex Hull</h1>
<p>Dado Varios pontos Descobrir o maior poligono que pode ser formado</p>

<h2>Logica -Granham Scan O(n log n)- </h2>
<ul>
		<li>Primeiro é escolhido um vertice garantido no Convex Hull, no caso      o vertice mais a esquerda ou seja com a menor das abcissas</li>
		<li>Depois ordena-se os vertices baseados no ângulo dos pontos (ponto base com y +1, ponto base, ponto atual)</li>
		<li>Para todos os agulos, verifica se o angulo do atual for maior que o angulo anterior, substiui, caso contrario apenas incrementa ao ConvexHull</li>
		<h2>Geometria</h2>
		<ul>
			<li>A formula para o calculo de um ângulo a partir de 3 pontos é :
			
	vetores BA, BC

	produtoEscalar = BA.x*BC.x + BA.y*BC.y 

	cumprimento do vetorBA = sqrt(BA.x * BA.x + BA.y * BA.y)

	cumprimento do vetorCB = sqrt(CB.x * CB.x + CB.y * CB.y)

	cumpimento dos vetores

	cosseno = produto escalar / cumprimento dos vetores

	angulo = arco cosseno de (cosseno) * 180/π
</ul>
</ul>