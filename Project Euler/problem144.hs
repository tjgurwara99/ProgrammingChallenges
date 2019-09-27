import Data.Maybe
import Data.List

type Vec2 = (Double, Double)

intersection :: Vec2 -> Vec2 -> Vec2
intersection (x,y) (dx,dy) = (x+l*dx,y+l*dy)
  where l = -(8*x*dx+2*y*dy) / (4*dx*dx+dy*dy) -- solution to intersect eqn

reflect :: Vec2 -> Vec2 -> Vec2
reflect (x1,y1) (x2,y2) = (dx-sf*nx, dy-sf*ny)
  where (nx,ny) = (4*x2, y2) -- normal to the ellipse at (x2,y2)
        (dx,dy) = (x2-x1,y2-y1)
        sf = 2*(dx*nx+dy*ny) / (nx*nx+ny*ny)

solve :: Int
solve = fromJust $ findIndex (isSolution . snd) points
  where points = iterate step ((0,10.1),(1.4,-9.6))
        isSolution (x,y) = abs x <= 0.01 && y > 0
        step (u,v) = (v, intersection v (reflect u v))

main :: IO ()
main = print solve
